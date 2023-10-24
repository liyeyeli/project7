#pragma once
#ifndef __FOOD_H__
#define __FOOD_H__

#include "Circle.h"
#include "Mapclass.h"
#include <stdbool.h>
#include <time.h>


class food
{
public:
	void FoodEmerge(Map m,Screen* s);//食物产生函数
private:
	Circle* c;
	int fcolor;
};
#endif