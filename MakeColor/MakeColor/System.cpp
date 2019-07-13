#include <iostream>
#include <random>
#include "System.h"
using namespace std;

System::System()
{
}

void System::selectSuggestingColor()
{
	unsigned short r = rand() % 8;
	suggestColor = suggestColors[r];
}
void System::randNum()
{
	int n;
	bool zero = false, one = false, two = false, three = false;
	for (unsigned short i = 0; i < 4; i++)
	{
		n = rand() % 4;
		
		if (n == 0)
		{
			if (zero)
			{
				i--;
				continue;
			}
			zero = true;
		}
		else if (n == 1)
		{
			if (one)
			{
				i--;
				continue;
			}
			one = true;
		}
		else if (n == 2)
		{
			if (two)
			{
				i--;
				continue;
			}
			two = true;
		}
		else if (n == 3)
		{
			if (three)
			{
				i--;
				continue;
			}
			three = true;
		}
		randNums[i] = n;
	}
}
void System::drawSuggestColor()
{
	gotoxy(suggestColorX - 2, suggestColorY - 1);
	setBackgroundColor(suggestColor);
	setTextColor(suggestColor);
	cout << "¡á¡á¡á";
	gotoxy(suggestColorX - 2, suggestColorY);
	cout << "¡á¡á¡á";
	gotoxy(suggestColorX - 2, suggestColorY + 1);
	cout << "¡á¡á¡á";
	setBackgroundColor(ColorWhite);
	setTextColor(ColorWhite);
}
void System::drawTimer()
{
	gotoxy(showingTimeX, showingTimeY);
	for (unsigned short i = 0; i <= (startTime + showingTime - clock()) / (showingTime / 10); i++)	cout << "  ";
}
void System::drawColors()
{
	gotoxy(colorsPos[0][0], colorsPos[0][1]);
	setBackgroundColor(randColors[randNums[0]]);
	cout << "  ";
	gotoxy(colorsPos[1][0], colorsPos[1][1]);
	setBackgroundColor(randColors[randNums[1]]);
	cout << "  ";
	gotoxy(colorsPos[2][0], colorsPos[2][1]);
	setBackgroundColor(randColors[randNums[2]]);
	cout << "  ";
	gotoxy(colorsPos[3][0], colorsPos[3][1]);
	setBackgroundColor(randColors[randNums[3]]);
	cout << "  ";

	setBackgroundColor(ColorBlack);
}
void System::draw()
{
	drawSuggestColor();
	drawTimer();
	drawColors();
	showScore();
}

void System::checkColor(Alter &alter)
{
	if (suggestColor == alter.alterColor)
	{
		score += 100;
		clear = true;
	}
}

void System::showScore()
{
	gotoxy(scoreX, scoreY);
	cout << score;
}