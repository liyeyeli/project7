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
	//��Ļ����¼�������������x��y����
	void get_coordinate(int& x, int& y);
	~touch();
private:
	int fd;
};