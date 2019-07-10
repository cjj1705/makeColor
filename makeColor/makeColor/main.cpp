#include <iostream>
#include "ConsoleFunctions.h"
using namespace std;

#define WindowWidth 80
#define WindowHeight 25

int main()
{
	// 초기 세팅
	setSize(WindowWidth, WindowHeight);

	// 변수
	bool isGameFinished = false;

	// 게임 루프
	while (!isGameFinished)
	{
		if (_getch() == 37) // 왼쪽
		{

		}
		else if (_getch() == 38) // 위 
		{

		}
		else if (_getch() == 39) // 오른쪽
		{

		}
		else if (_getch() == 40) // 아래
		{

		}
	}
}