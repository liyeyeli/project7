
#include "Circle.h"
#include "Shape.h"
#include "Screen.h"

#include <iostream>

using namespace std;

//构造函数 
Circle::Circle( int _x, int _y, int _r, int _color)
	: radius(_r), Shape( _x, _y, _color )
{}


//显示 
void Circle::draw( Screen *s )
{
	int i,j;

	for( j=y0-radius; j<y0+radius; j++ )
	{
		for( i=x0-radius; i<x0+radius; i++ )
		{
			//圆方程
			if( (i-x0)*(i-x0) + (j-y0)*(j-y0) <= radius*radius )
			{
				s->display_point( i, j, color );
			}
		}
	}
}

void Circle::set_r( int _r )
{
	radius = _r;
}
int Circle::get_r() const
{
	return radius;
}



