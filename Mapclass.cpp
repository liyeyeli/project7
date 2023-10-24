#include "Mapclass.h"
using namespace std;
Map::Map(int color) :bg_color(bg_color)
{
	bg_color = color;
	//һ��Ҫ��סҪ����ռ䣡����
	cells = new Rectangle * [MAP_ROWS];

	for (int i = 0; i < MAP_COLS; i++)
	{
		cells[i] = new Rectangle[MAP_COLS];
	}
}

void Map::draw( Screen*s )
{
	int i,j;
	for (i = 0; i < MAP_ROWS; i++)
	{
		for (j = 0; j < MAP_COLS; j++)
		{
			//����ÿһ��Ԫ��ĳ���ͼλ���Լ�������ɫ
			cells[i][j].set_w(CELL_SIZE);
	
			cells[i][j].set_h(CELL_SIZE);
			
			cells[i][j].set_x(j * CELL_SIZE);
			cells[i][j].set_y(i * CELL_SIZE);
		
			cells[i][j].set_color(bg_color);
			
			cells[i][j].draw(s);
			
		}
	}
}
void Map::flush(int x, int y)
{
	cells[x / CELL_SIZE][y / CELL_SIZE].set_color(bg_color);//��xy����ĵ�Ԫ��ԭ�ɱ�����ɫ
}
Map::~Map()
{
	if (cells)
	{
		delete[]cells;
	}
}