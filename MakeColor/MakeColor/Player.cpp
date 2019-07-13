#include <iostream>
#include "Player.h"
#include "Init.h"

Player::Player()
{
}

void Player::moveUp()
{
	setPosition(x, y - 1);
}
void Player::moveDown()
{
	setPosition(x, y + 1);
}
void Player::moveLeft()
{
	setPosition(x - 2, y);
}
void Player::moveRight()
{
	setPosition(x + 2, y);
}

void Player::paste(Alter &alter)
{
	if (onBackgroundColor != ColorWhite)
		myColor = onBackgroundColor;
	if (x == alter.x && y == alter.y)
	{
		alter.setAlterColor(myColor);
		myColor = ColorWhite;
	}
}

void Player::setPosition(int _x, int _y)
{
	if (_x < 0)
		_x = 0;
	else if (_x > WindowWidth - 2)
		_x = WindowWidth - 2;
	if (_y < 0)
		_y = 0;
	else if (_y > WindowHeight - 1)
		_y = WindowHeight - 1;
	x = _x;
	y = _y;
}

void Player::draw(System &control)
{
	gotoxy(x, y);
	for (unsigned short i = 0; i < 4; i++)
	{
		if ((x == control.colorsPos[i][0] || x == control.colorsPos[i][0] + 1) && y == control.colorsPos[i][1])
		{
			switch (control.randNums[i])
			{
			case 0:
				setBackgroundColor(ColorRed);
				onBackgroundColor = ColorRed;
				break;
			case 1:
				setBackgroundColor(ColorYellow);
				onBackgroundColor = ColorYellow;
				break;
			case 2:
				setBackgroundColor(ColorGreen);
				onBackgroundColor = ColorGreen;
				break;
			case 3:
				setBackgroundColor(ColorBlue);
				onBackgroundColor = ColorBlue;
				break;
			}
		}
		else
		{
			setBackgroundColor(ColorWhite);
			onBackgroundColor = ColorWhite;
		}
		if (onBackgroundColor != ColorWhite)
			break;
	}

	setTextColor(myColor);
	std::cout << "бс";
	setBackgroundColor(ColorBlack);
	setTextColor(ColorWhite);
}