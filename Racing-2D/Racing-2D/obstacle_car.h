#pragma once
#include <iostream>
#include "Console.h"

struct Ob_car
{
	int X = 0;
	int Y = 0;

	void ShowCar()
	{
		console.SetCursorPosition(X, Y);
		ShowFrontWeels();
		console.SetCursorPosition(X, Y + 1);
		ShowRoof();
		console.SetCursorPosition(X, Y + 2);
		ShowBackWeels();
	}

	void DropObstacleCar()
	{
		Y = 0;
		X = (rand() % (15 - 4)) + 4;
	}

	void MoveDown()
	{
		Y++;
	}

private:

	Console console;

	void ShowFrontWeels()
	{
		std::cout << "o o";
	}
	void ShowRoof()
	{
		std::cout << " " << (char)177;
	}
	void ShowBackWeels()
	{
		std::cout << "o o";
	}
};