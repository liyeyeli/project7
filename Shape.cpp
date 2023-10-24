
#include "Shape.h"
#include <iostream>

using namespace std;


//构造函数 
Shape::Shape( int _x, int _y, int _color) : x0(_x), y0(_y), color(_color)
{
}


//设置
void Shape::set_color( int _color )
{
	color = _color;
}
void Shape::set_x( int _x )
{
	x0 = _x;
}
void Shape::set_y( int _y )
{
	y0 = _y;
}

//获取 
int Shape::get_x() const
{
	return x0;
}
int Shape::get_y() const
{
	return y0;
}
int Shape::get_color() const
{
	return color;
}




