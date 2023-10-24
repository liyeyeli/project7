#pragma once
#include "Screen.h"
#include "Rectangle.h"
#define CELL_SIZE 10 //��Ԫ���С
#define MAP_COLS 48 // ��
#define MAP_ROWS 48 //��
class Map
{
public:
	//���캯��
	Map(int color);
	void draw(Screen* s);
	void flush(int x, int y); //�ѣ�x��y�����껹ԭ�ɵ�ͼ������ɫ
	Rectangle** get_cells()
	{
		return cells;
	}
	~Map();

private:
	int bg_color; //��ͼ������ɫ
	//Rectangle* cells[MAP_ROWS][MAP_COLS];
	Rectangle** cells;//������ά����
};