
#include "Bmp.h"
#include "Screen.h"

#include <iostream>
#include <string>

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

//构造函数
Bmp::Bmp( std::string _pathname) : pathname(_pathname)
{
	//打开图片
	int fd = open( pathname.c_str() , O_RDWR );
	if( fd == -1 )
	{
	perror("open bmp error ");
	return ;
	}

	//读取宽/高/色深
	lseek( fd, 0x12, SEEK_SET );
	read( fd, &width, 4 );
	read( fd, &height, 4 );

	lseek( fd, 0x1C, SEEK_SET );
	read( fd, &depth, 2 );

	int line_size = 0;	//保存一行实际的字节数
	laizi = 0;		//填充的字节数 "赖子"

	laizi = 4 - (abs(width)*(depth/8))%4;
	if( laizi == 4 )
	{
		laizi = 0;
	}
	//一行实际的字节数 = 有效字节数 + 赖子 
	line_size = abs(width)*(depth/8) + laizi;

	//读取像素点颜色数据
	pixel = (unsigned char *)malloc( abs(height)*line_size );
	lseek( fd, 0x36, SEEK_SET );
	read( fd, pixel, abs(height)*line_size );

	//关闭图片
	close( fd );
}

//析构函数
Bmp::~Bmp()
{
	free( pixel );
	cout << "已释放内存! " << endl;
}

//显示
void Bmp::draw( Screen *s ,int x0, int y0 ) const
{
	int count = 0;
	int i,j;
	unsigned char b,g,r,a=0;
	int color;

	for( j=0; j<abs(height); j++ )
	{
		for( i=0; i<abs(width); i++ )
		{
			b = pixel[count++];
			g = pixel[count++];
			r = pixel[count++];
			if( depth == 32 )
			{
				a = pixel[count++];
			}
			color = (a<<24)|(r<<16)|(g<<8)|b;

			s->display_point( width>0 ? i+x0 : abs(width)-1-i+x0 , 
							height>0 ? abs(height)-1-j+y0 : j+y0 , 
							color );
		}
		count = count + laizi;	//跳过填充的数据
	}
}

//打印图片的信息 
void Bmp::print_info() const
{
	cout << pathname << " : " ;
	cout << "w = " << width << ", h = " << height << " , d = " << depth << endl;
	
}



