#pragma once
#include <iostream>
#include <conio.h>
#include "Console.h"
#include "obstacle_car.h"

struct Move
{
public:

	void MoveCar(int& X, int& Y)
	{
		int pressedKey = DectectKey();

		if (pressedKey == left)
			MoveLeft(X, Y);
		else if (pressedKey == right)
			MoveRight(X, Y);
	}

private:

	enum direction
	{
		left = 75,
		right = 77
	};

	int DectectKey()
	{
		int usless = _getch();
		int key = _getch();

		if (key == left)
			return left;

		else if (key == right)
			return right;
	}

	void MoveLeft(int& X, int& Y)
	{
		X--;
	}

	void MoveRight(int& X, int& Y)
	{
		X++;
	}
};

struct Car
{
	int X = 10;
	int Y = 24;

	void ShowCar()
	{
		console.SetCursorPosition(X, Y);
		ShowFrontWeels();
		console.SetCursorPosition(X, Y + 1);
		ShowRoof();
		console.SetCursorPosition(X, Y + 2);
		ShowBackWeels();
	}

	void MoveCar()
	{
		move.MoveCar(X, Y);
	}

	bool IsCarCrashed(Ob_car& _ob_car)
	{
		if (Ycrashed(_ob_car))
		{
			if (Xcrashed(_ob_car))
				return true;
			else
				return false;
		}
		
		else
			return false;
	}

	bool IsWallCrashed()
	{
		if (X == 3 || X == 15)
			return true;
		else
			return false;
	}

	bool IsMissedOb_car(Ob_car& _ob_car)
	{
		if (_ob_car.Y + 4 > Y + 6)
			return true;
		else
			return false;
	}

private:

	Move move;
	Console console;

	bool Xcrashed(Ob_car& _ob_car)
	{
		if (_ob_car.X == X || _ob_car.X == X + 1 || _ob_car.X == X + 2 || _ob_car.X + 1 == X || _ob_car.X + 1 == X + 1 || _ob_car.X + 1 == X + 2 || _ob_car.X + 2 == X || _ob_car.X + 2 == X + 1 || _ob_car.X + 2 == X + 2)
			return true;
		else
			return false;
	}
	bool Ycrashed(Ob_car& _ob_car)
	{
		if (_ob_car.Y + 1 == Y)
			return true;
		else
			return false;
	}

	void ShowFrontWeels()
	{
		std::cout << "o o";
	}
	void ShowRoof()
	{
		std::cout << " " << (char)178;
	}
	void ShowBackWeels()
	{
		std::cout << "o o";
	}
};
