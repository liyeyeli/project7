
#include "Screen.h"
#include <iostream>

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

using namespace std;

//初始化
Screen* Screen::only_one = nullptr;


//全局访问点 -->获取屏幕的唯一实例
Screen* Screen::get_screen(const char *dev_name)
{
	if( only_one == nullptr )
	{
		only_one = new Screen( dev_name );
	}
	return only_one;
}

//销毁
void Screen::destroy_screen()
{
	if( only_one )
	{
		delete only_one;
		only_one = nullptr;
	}
}



//构造函数 --> 打开屏幕/获取屏幕参数/内存映射 
Screen::Screen( const char *dev_name ) : filename(dev_name), fd(-1), plcd(NULL), lcd_width(800), lcd_height(480), bits_per_pixel(32)
{
	//打开屏幕
	fd = open( dev_name, O_RDWR );
	if( fd == -1 )
	{
		perror("open dev error ");
		return ;
	}

	/*
	//获取屏幕参数
	struct fb_var_screeninfo  info;
	int re = ioctl( fd, FBIOGET_VSCREENINFO, &info );
	if( re == -1 )
	{
		perror("ioctl error ");
		return ;
	}

	lcd_width = info.xres;
	lcd_height = info.yres;
	bits_per_pixel = info.bits_per_pixel;
	*/

	//内存映射
	plcd = (int *)mmap( NULL, lcd_width*lcd_height*(bits_per_pixel/8), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if( plcd == MAP_FAILED )
	{
		perror("mmap error ");
		return ;
	}
}


//析构函数 --> 解除映射/关闭屏幕
Screen::~Screen()
{
	//解除映射
	munmap( plcd, lcd_width*lcd_height*(bits_per_pixel/8) );

	//关闭屏幕
	close( fd );
}


//画点
void Screen::display_point(int x, int y, int color)
{
	if( x>=0 && x<lcd_width && y>=0 && y<lcd_height )
	{
		*(plcd + y*lcd_width + x ) = color;
	}
}


