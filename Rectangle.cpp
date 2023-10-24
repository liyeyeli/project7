
#include "Rectangle.h"
#include "Screen.h"
#include "Shape.h"


//构造函数 
Rectangle::Rectangle( int _x, int _y, int _w, int _h, int _color)
	: w(_w), h(_h), Shape( _x, _y, _color )
{

}


//显示
void Rectangle::draw( Screen *s )
{
	int i,j;
	
	for( j=y0; j<y0+h; j++ )
	{
		for( i=x0; i<x0+w; i++ )
		{
			//画点
			s->display_point( i , j , color );
		}
	}
}


//设置 
void Rectangle::set_w( int _w )
{
	w = _w;
}
void Rectangle::set_h( int _h )
{
	h = _h;
}
//获取
int Rectangle::get_w() const
{
	return w;
}
int Rectangle::get_h() const
{
	return h;
}


