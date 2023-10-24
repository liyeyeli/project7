
#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <iostream>

//屏幕 --> 单例模式
class Screen
{
private:
	const char * filename;	//屏幕的设备文件名
	int fd;					//文件描述符
	int lcd_width;			//屏幕宽度
	int lcd_height;			//屏幕高度
	int bits_per_pixel;		//屏幕像素点所占的bit位数
	int * plcd;				//帧缓冲的首地址

	static Screen * only_one;	//指向屏幕类的唯一的实例

protected:
	//构造函数 --> 打开屏幕/获取屏幕参数/内存映射 
	Screen( const char *dev_name="/dev/fb0" );

	//拷贝构造函数 
	Screen( const Screen & ) = delete;

	//析构函数 --> 解除映射/关闭屏幕
	~Screen();


public:
	//画点
	void display_point(int x, int y, int color);

	//全局访问点 
	static Screen* get_screen(const char *dev_name);

	static void destroy_screen();
};



/*
//屏幕 
class Screen
{
private:
	const char * filename;	//屏幕的设备文件名
	int fd;					//文件描述符
	int lcd_width;			//屏幕宽度
	int lcd_height;			//屏幕高度
	int bits_per_pixel;		//屏幕像素点所占的bit位数
	int * plcd;				//帧缓冲的首地址

public:
	//构造函数 --> 打开屏幕/获取屏幕参数/内存映射 
	Screen( const char *dev_name="/dev/fb0" );

	//析构函数 --> 解除映射/关闭屏幕
	~Screen();

	//画点
	void display_point(int x, int y, int color);

	// ... 
};
*/


#endif

