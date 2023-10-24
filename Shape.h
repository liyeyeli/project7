
#ifndef __SHAPE_H__
#define __SHAPE_H__


//形状类 --> 基类 
class Shape
{
protected:
    int x0;     //位置 
    int y0;
    int color;  //颜色 

public:
    //构造函数 
    Shape( int _x=0, int _y=0, int _color=0);

    //析构函数 
    ~Shape()
    {}

    //设置
    void set_color( int _color );
    void set_x( int _x );
    void set_y( int _y );
    //获取 
    int get_x() const;
    int get_y() const;
    int get_color() const;
    //...
};


#endif

