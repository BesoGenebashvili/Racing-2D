#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include "player_car.h"
#include "Console.h"
#include "road.h"
#include "obstacle_car.h"
#include "player.h"
using namespace std;

int main()
{
	srand(time(NULL));

	Player player;
	Car playerCar;
	Ob_car obstacleCar;
	Console console;

	cout << endl;
	cout << "   3" << endl;
	Sleep(800);
	cout << "   2" << endl;
	Sleep(800);
	cout << "   1" << endl;
	Sleep(800);
	cout << "   GO!" << endl;
	Sleep(900);
	console.ClearScreen();

	console.ShowConsoleCursor(false);
	obstacleCar.DropObstacleCar();

	while (true)
	{
		DrawRoad(player);

		if (_kbhit())
		{
			playerCar.MoveCar();
			console.SetCursorPosition(playerCar.X, playerCar.Y);
		}

		playerCar.ShowCar();

		obstacleCar.ShowCar();
		obstacleCar.MoveDown();

		if (playerCar.IsCarCrashed(obstacleCar))
		{
			console.SetCursorPosition(4, 13);
			cout << "[SCORE -  " << player.GetScore() << "]" << endl;
			console.SetCursorPosition(4, 14);
			cout << "[YOU CRASHED]";
			Sleep(3000);
			break;
		}

		if (playerCar.IsWallCrashed())
		{
			console.SetCursorPosition(4, 13);
			cout << "[SCORE -  " << player.GetScore() << "]" << endl;
			console.SetCursorPosition(4, 14);
			cout << "[YOU CRASHED]";
			Sleep(3000);
			break;
		}

		if (playerCar.IsMissedOb_car(obstacleCar))
		{
			player.AddScore();
			obstacleCar.DropObstacleCar();
		}

		Sleep(130);
		console.ClearScreen();
	}

	console.ClearScreen();
	
	cin.get();
	cin.get();
	return 0;
}