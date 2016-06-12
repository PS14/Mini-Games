#pragma once
#include "../Object/Object.h"

bool Swappable(int32 a, int32 b)
{
	return (a / 4 == b / 4 && Abs(a - b) == 1) || (a % 4 == b % 4 && Abs(a - b) == 4);
}

bool hit3(float x1, float y1, float r, float x2, float y2) 
{
	bool circle_hit = false;
	if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) < (r*r)) 
	{
		return true;
	}
	return false;
}