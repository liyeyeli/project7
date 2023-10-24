
#ifndef __BMP_H__
#define __BMP_H__

#include "Screen.h"
#include <string>

/*
	属性: 带路径的图片名, 宽度, 高度, 色深, 像素点数据char *pixel  //  ... 
    行为: 
        //构造函数: 打开图片, 读取宽/高/色深, 读取像素点颜色数据, 关闭图片 
        //析构函数 :释放空间pixel
        //显示 draw( Screen &s , int x0, int y0 ); 
        // ... 
*/
class Bmp
{
private:
	std::string pathname;	//带路径的图片名
	int width;		//宽度
	int height;		//高度
	short depth;	//色深
	int laizi;		//填充的字节数 "赖子"
	unsigned char *pixel;	//像素点颜色数据首地址

public:
	//构造函数
	Bmp( std::string _pathname);

	//析构函数
	~Bmp();

	//显示
	void draw( Screen *s ,int x0, int y0 ) const;

	//打印图片的信息 
	void print_info() const;
};

#endif



