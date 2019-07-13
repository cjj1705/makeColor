#include <iostream>
#include "ConsoleFunctions.h"
#include "Init.h"
#include "Player.h"
#include "System.h"
#include "Alter.h"

inline void update();
inline void render();

System control;
Player player;
Alter alter;

bool isGameFinished;

int main()
{
	// 초기 설정
	setTitle("makeColor");
	setSize(WindowWidth, WindowHeight);
	setCursorType(CursorInvisible);

	// 시스템 관련 변수
	control.clear = true;
	isGameFinished = false;

	// 게임 루프
	for (;;)
	{
		update();
		render();
		Sleep(1000 / 60);
		if (isGameFinished)
			break;
	}

	clearConsole();
	gotoxy(35, 12);
	std::cout << "GAME  OVER";
}

inline void update()
{
	if (_kbhit())
	{
		switch (_getch())
		{
			case ARROW_UP :
				player.moveUp();
				break;
			case ARROW_DOWN :
				player.moveDown();
				break;
			case ARROW_LEFT :
				player.moveLeft();
				break;
			case ARROW_RIGHT :
				player.moveRight();
				break;
			case KEY_Z :
				player.paste(alter);
				control.checkColor(alter);
				break;
			case KEY_X :
				alter.clearAlter();
				break;
		}
	}

	if (control.clear)
	{
		control.randNum();
		control.selectSuggestingColor();
		control.startTime = clock();
		alter.clearAlter();
		control.clear = false;
	}
	else if (clock() - control.startTime >= control.showingTime)
	{
		if (!--player.hp)
			isGameFinished = true;
		else
			control.clear = true;
	}
}

inline void render()
{
	clearConsole();
	control.draw();	
	alter.draw();
	player.draw(control);
}