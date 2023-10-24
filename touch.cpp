#include "touch.h"

touch::touch()
{
	fd = open("/dev/input/event0", O_RDWR);
}
//屏幕点击事件，并保存点击的x，y坐标
void touch::get_coordinate(int &x, int &y)
{
	struct input_event et;
	while (1)
	{
		int r = read(fd, &et, sizeof(et));
		if (r == sizeof(et))
		{
			if (et.type == EV_ABS && et.code == ABS_X)//获取x轴坐标
			{
				x = et.value * (1.0 * 800 / 1024);
			}
			if (et.type == EV_ABS && et.code == ABS_Y)//获取y轴坐标
			{
				y = et.value * (1.0 * 480 / 600);
			}

			if (et.type == EV_KEY && et.code == BTN_TOUCH)//手指离开屏幕
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



