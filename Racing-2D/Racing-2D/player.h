#pragma once
#include <string>

struct Player
{
private:
	int score = 0;

public:

	void ResetScore()
	{
		score = 0;
	}

	void AddScore()
	{
		score += 10;
	}

	int GetScore()
	{
		return score;
	}
};