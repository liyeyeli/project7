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