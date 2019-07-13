#include <iostream>
#include "Alter.h"
using namespace std;

Alter::Alter()
{
}

void Alter::setAlterColor(Color &color)
{
	Color setColor = color;
	if (alterColor != ColorWhite && alterColor != color)
	{
		switch (alterColor)
		{
		case ColorRed:
			switch (color)
			{
			case ColorYellow:
				setColor = ColorLightRed;
				break;
			case ColorGreen:
				setColor = ColorYellow;
				break;
			case ColorBlue:
				setColor = ColorPurple;
				break;
			}
			break;
		case ColorYellow:
			switch (color)
			{
			case ColorRed:
				setColor = ColorLightRed;
				break;
			case ColorGreen:
				setColor = ColorLightGreen;
				break;
			case ColorBlue:
				setColor = ColorGreen;
				break;
			}
			break;
		case ColorGreen:
			switch (color)
			{
			case ColorRed:
				setColor = ColorYellow;
				break;
			case ColorYellow:
				setColor = ColorLightGreen;
				break;
			case ColorBlue:
				setColor = ColorLightBlue;
				break;
			}
			break;
		case ColorBlue:
			switch (color)
			{
			case ColorRed:
				setColor = ColorPurple;
				break;
			case ColorYellow:
				setColor = ColorGreen;
				break;
			case ColorGreen:
				setColor = ColorLightBlue;
				break;
			}
			break;
		}
	}
	alterColor = setColor;
}
void Alter::draw()
{
	gotoxy(x - 2, y - 1);
	cout << "бсбсбс";

	gotoxy(x - 2, y);
	cout << "бс";
	if (alterColor != ColorWhite)
	{
		setBackgroundColor(ColorWhite);
		setTextColor(alterColor);
		cout << "бс";
		setBackgroundColor(ColorBlack);
		setTextColor(ColorWhite);
	}
	else
		cout << "бр";

	cout << "бс";

	gotoxy(x - 2, y + 1);
	cout << "бсбсбс";
}
void Alter::clearAlter()
{
	alterColor = ColorWhite;
}