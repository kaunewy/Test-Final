#pragma once
#include "Macro.h"
struct Position
{
	u_int x;
	u_int y;

	Position() = default;

	Position(u_int _x, u_int _y)
	{
		x = _x;
		y = _y;
	}
};