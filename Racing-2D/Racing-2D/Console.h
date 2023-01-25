#pragma once
#include <Windows.h>

struct Console
{
	static void ClearScreen()
	{
		system("cls");
	}

	static void SetCursorPosition(int x, int y)
	{
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { x,y };
		SetConsoleCursorPosition(output, pos);
	}

	void ShowConsoleCursor(bool showFlag)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_CURSOR_INFO     cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = showFlag;
		SetConsoleCursorInfo(out, &cursorInfo);
	}
};