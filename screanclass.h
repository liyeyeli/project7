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
	//��ʾbmpͼƬ
	void show_bmp(int x, int y, const char* pic);
	//���㺯��
	void draw_point(int x, int y,int color);
	//�����νӿ�
	void draw_juxing(int color, int w, int h);
	~LCD();
private:
	int fd;//�ļ�������
	unsigned int* lcd_p;
};
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