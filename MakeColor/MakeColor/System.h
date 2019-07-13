#pragma once
#include "ConsoleFunctions.h"
#include "Alter.h"
class System
{
public:
	System();

	unsigned short randNums[4];
	unsigned short colorsPos[4][2] = { {16, 12}, {26, 8}, {54, 8}, {64, 12} };
	Color randColors[4] = { ColorRed, ColorYellow, ColorGreen, ColorBlue };
	
	unsigned short suggestColorX = 40, suggestColorY = 2;
	Color suggestColor;
	Color suggestColors[8] = { ColorRed, ColorLightRed, ColorYellow, ColorLightGreen, ColorGreen, ColorLightBlue, ColorBlue, ColorPurple };

	unsigned short showingTimeX = 58, showingTimeY = 2;
	unsigned short showingTime = 30000;
	bool clear = false;
	clock_t startTime;

	unsigned short score = 0;
	unsigned short scoreX = 10, scoreY = 2;

	void selectSuggestingColor();
	void randNum();
	void drawSuggestColor();
	void drawTimer();
	void drawColors();
	void draw();

	void checkColor(Alter &alter);

	void showScore();
};