#include "food.h"
#include <iostream>
#include "touch.h"
using namespace std;
bool OneorZero = false;
#define FOODSIZE 5
int FOODX;
int FOODY;

void food::FoodEmerge( Map m,Screen* s)
{
	if (!OneorZero)
	{
		int x, y;
		touch t;
		//测试随机产生食物
		//while (1)
		//{
			//t.get_coordinate(x, y);
			srand(time(NULL));
			int N[2] = { 0x00ff0000,0x000000ff };
			fcolor = N[rand() % 2];//让颜色在n数组内0，1随机
			do
			{
				FOODX = rand() % 48;
				FOODY = rand() % 48;
			} while (m.get_cells()[FOODX][FOODY].get_color() != 0X0000ff00);
			c->set_color(this->fcolor);
			c->set_r(FOODSIZE);
			c->set_x((FOODX * CELL_SIZE) + (CELL_SIZE / 2));
			c->set_y((FOODY * CELL_SIZE) + (CELL_SIZE / 2));
			c->draw(s);
			OneorZero = true;
		//}
	}
}