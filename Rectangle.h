
#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Screen.h"
#include "Shape.h"

//矩形 --> 继承 Shape 形状类
class Rectangle : public Shape
{
private:
	int w;	//宽度
	int h;	//高度

public:
	//构造函数 
	Rectangle( int _x=0, int _y=0, int _w=0, int _h=0, int _color=0xFFFFFF);
	
	//析构函数
	~Rectangle()
	{}

	//显示
	void draw( Screen *s );

	//设置 
    void set_w( int _w );
    void set_h( int _h );
    //获取
    int get_w() const;
    int get_h() const;
};


/*
//矩形 
class Rectangle
{
private:
	int w;	//宽度
	int h;	//高度
	int defualt_fill_color;	  //默认填充的颜色

public:
	//构造函数 
	Rectangle( int _w, int _h, int _color=0xFFFFFF) : w(_w), h(_h), defualt_fill_color(_color)
	{}

	//析构函数
	~Rectangle()
	{}

	//显示
	void draw( Screen *s, int x0, int y0 );
};
*/

#endif


