#pragma once
#include "Screen.h"
#include "Rectangle.h"
#define CELL_SIZE 10 //单元格大小
#define MAP_COLS 48 // 列
#define MAP_ROWS 48 //行
class Map
{
public:
	//构造函数
	Map(int color);
	void draw(Screen* s);
	void flush(int x, int y); //把（x，y）坐标还原成地图背景颜色
	Rectangle** get_cells()
	{
		return cells;
	}
	~Map();

private:
	int bg_color; //地图背景颜色
	//Rectangle* cells[MAP_ROWS][MAP_COLS];
	Rectangle** cells;//创建二维数组
};