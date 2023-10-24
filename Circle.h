
#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Shape.h"
#include "Screen.h"

//圆 --> 继承 Shape 形状类
class Circle : public Shape
{
private:
	int radius;

public: 
	//构造函数 
	Circle( int _x=0, int _y=0, int _r=0, int _color=0xFFFFFF);

	//析构函数 
	~Circle()
	{}

	//显示 
	void draw( Screen *s );

	void set_r( int _r );
	int get_r() const;
};


#endif

