#include "touch.h"

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



