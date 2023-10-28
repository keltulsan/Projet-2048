#pragma once

#include "Grid.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_Z 122
#define KEY_S 115
#define KEY_Q 113
#define KEY_D 100

class Game
{
private:
	int sizeX;
	int sizeY;

public :
	Game(int x, int y);

	void startGame();
	void restartGame();
};