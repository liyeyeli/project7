#include "screanclass.h"


int main()
{
	touch a;
	LCD b;
	int i = 0, x = 0, y = 0;
	while (1)
	{
		b.show_bmp(0,0,"1.bmp");
		a.get_coordinate(x, y);
		if (x > 280 && x < 520 && y>270 && y < 330)
		{
			b.show_bmp(0, 0, "2.bmp");
			b.draw_juxing(0x00ffffff, 480, 480);
		}
		a.get_coordinate(x, y);
	}
	return 0;
}