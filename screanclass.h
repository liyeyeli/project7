#pragma once
#include<iostream>
#include<sys/mman.h>
using namespace std;

extern "C"
{
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/input.h>
}
class LCD
{
public:
	LCD();
	//显示bmp图片
	void show_bmp(int x, int y, const char* pic);
	//画点函数
	void draw_point(int x, int y,int color);
	//画矩形接口
	void draw_juxing(int color, int w, int h);
	~LCD();
private:
	int fd;//文件描述符
	unsigned int* lcd_p;
};
class touch
{
public:
	touch();
	//屏幕点击事件，并保存点击的x，y坐标
	void get_coordinate(int& x, int& y);
	~touch();
private:
	int fd;
};