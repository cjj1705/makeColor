#pragma once
#include "ConsoleFunctions.h"
#include "System.h"
#include "Alter.h"
class Player
{
	unsigned short x = 40, y = 13;
public:
	Player();

	unsigned short hp = 3;
	Color onBackgroundColor, myColor = ColorWhite;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void paste(Alter &alter);

	void setPosition(int _x, int _y);
	void draw(System &control);
};