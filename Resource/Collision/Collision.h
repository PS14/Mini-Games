#pragma once
#include "../Object/Object.h"

bool Swappable(int32 a, int32 b)
{
	return (a / 4 == b / 4 && Abs(a - b) == 1) || (a % 4 == b % 4 && Abs(a - b) == 4);
}