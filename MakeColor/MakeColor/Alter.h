#pragma once
#include "ConsoleFunctions.h"
class Alter
{
public:
	Alter();

	unsigned short x = 40, y = 21;
	Color alterColor = ColorWhite;

	void setAlterColor(Color &color);
	void draw();
	void clearAlter();
};