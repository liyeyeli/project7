#include "screanclass.h"


LCD::LCD()
{
	fd = open("/dev/fb0", O_RDWR);//��lcd��
	if (fd == -1)
	{
		cerr << "lcdopen fail!" << endl;
	}
	lcd_p = (unsigned int*)mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
}
//��ʾbmpͼƬ
void LCD::show_bmp(int x,int y,const char* pic)
{
	//bmp��ÿ��������ɶ�������4���ֽ�
	unsigned char buf[4];
	int fd1 = open(pic, O_RDONLY);
	//�ж��Ƿ�Ϊbmp�ļ�
	lseek(fd1, 0, SEEK_SET);
	read(fd1, buf, 2);
	if (buf[0] != 0x42 || buf[1] != 0x4D)
	{
		cerr << "this picture is not bmp" << endl;
	}
	//��λ�� 4�ֽ�
	int bmp_w = 0;
	lseek(fd1, 0x12, SEEK_SET);
	read(fd1, &bmp_w, 4);
	//��λ�� 4�ֽ�
	int bmp_h = 0;
	lseek(fd1, 0x16, SEEK_SET);
	read(fd1, &bmp_h, 4);
	//��ɫ�� 2�ֽ�
	int bmp_colordepth = 0;
	lseek(fd1, 0x1C, SEEK_SET);
	read(fd1, &bmp_colordepth, 2);
	printf("bmp:%ld %ld %ld", bmp_w, bmp_h, bmp_colordepth);
	//������������ݣ���ͨ�����㺯������
	lseek(fd1, 54, SEEK_SET);
	int i, j;
	//��������ۣ�
	// ���ɫ��Ϊ32
	//��Ϊbmp���ص��¼����Ϊ���̺�������Ҫ����λ����
	char bmp_R, bmp_B, bmp_A, bmp_G;
	for (i = bmp_h - 1; i >= 0; i--)
	{
		for (j = 0; j < bmp_w; j++)
		{
			int color = 0;
			if (bmp_colordepth == 32)
			{
				//���������Զ��ƶ���ĩβλ��
				//read(fd1, &color, bmp_colordepth / 8);
				read(fd1, &bmp_B, 1);
				read(fd1, &bmp_G, 1);
				read(fd1, &bmp_R, 1);
				read(fd1, &bmp_A, 1);
				color = bmp_A << 24 | bmp_R << 16 | bmp_G << 8 | bmp_B;
				*(lcd_p + x + j + (y + i) * 800) = color;
			}
			else if (bmp_colordepth == 24)
			{
				read(fd1, &bmp_B, 1);
				read(fd1, &bmp_G, 1);
				read(fd1, &bmp_R, 1);
				bmp_A = 0;
				color = bmp_A << 24 | bmp_R << 16 | bmp_G << 8 | bmp_B;
				//*(lcd_p + x + j + (y + i) * 800) = color;
				draw_point(x+j, y+i, color);
			}
		}
		lseek(fd1, (4 - bmp_colordepth / 8 * bmp_w % 4) % 4, SEEK_CUR);
	}
	close(fd1);
}
//���㺯��
void LCD::draw_point(int x, int y,int color)
{
	*(lcd_p + x + y * 800) = color;
}
//��Բ�νӿ�
//x,y��ʾԲ�ĵ����꣬r��ʾԲ�İ뾶
void LCD::draw_circle(int x, int y, int r, int color)
{
	for (int i = 0; i < 800; i++)
	{
		for (int j = 0; j < 480; j++)
		{
			if (((x - i) * (x - i) + (y - j) * (y - j)) == (r * r))
			{
				draw_point(i,j, color);
			}
		}
	}
}
//�����νӿ�
void LCD::draw_juxing(int color, int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			//*(lcd_p + x + y * 800) = color;
			draw_point(x, y, color);
		}
	}
}
LCD::~LCD()
{
	close(fd);
	munmap(lcd_p, 800 * 480 * 4);
}


touch::touch()
{
	fd = open("/dev/input/event0", O_RDWR);
}
//��Ļ����¼�������������x��y����
void touch::get_coordinate(int &x, int &y)
{
	struct input_event et;
	while (1)
	{
		int r = read(fd, &et, sizeof(et));
		if (r == sizeof(et))
		{
			if (et.type == EV_ABS && et.code == ABS_X)//��ȡx������
			{
				x = et.value * (1.0 * 800 / 1024);
			}
			if (et.type == EV_ABS && et.code == ABS_Y)//��ȡy������
			{
				y = et.value * (1.0 * 480 / 600);
			}

			if (et.type == EV_KEY && et.code == BTN_TOUCH)//��ָ�뿪��Ļ
			{
				if (et.value == 0)
				{
					break;
				}

			}
		}
	}
}
touch::~touch()
{
	close(fd);
}



