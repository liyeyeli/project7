#include "touch.h"
#include "Bmp.h"
#include "Screen.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Mapclass.h"
#include "food.h"
int main()
{
	touch a;
	Screen* s = Screen::get_screen("/dev/fb0"); //lcdÆÁ
	int i = 0, x = 0, y = 0;
	while (1)
	{
		Bmp b("1.bmp");
		b.draw(s, 0, 0);
		a.get_coordinate(x, y);
		if (x > 280 && x < 520 && y>270 && y < 330)
		{
			/*b.show_bmp(0, 0, "2.bmp");
			r.draw(0,0,0x00808080, 480, 480);
			b.draw_circle(35, 5, 5, 0x0000ff00);
			b.draw_juxing(20,0,0x0000ff00, 10, 10);
			b.draw_juxing(10,0,0x0000ff00, 10, 10);
			b.draw_juxing(0,0,0x0000ff00, 10, 10);*/
			Bmp b1("2.bmp");
			b1.draw(s, 0, 0);
			Rectangle r(0,0,480,480,0x00808080);
			r.draw(s);
			Map m(0x0000ff00);
			m.draw(s);
			food f;
			f.FoodEmerge(m, s);

		}
		a.get_coordinate(x, y);
		
	}
	return 0;
}