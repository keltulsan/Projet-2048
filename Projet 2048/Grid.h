#pragma once

#include <iostream>
#include <vector>
#include "Tile.h"

class Grid
{
private:
	int sizeX;
	int sizeY;
	int sizeMax;
	std::vector<Tile*> tab;

public:
	Grid(int x, int y);

	void display();
	int getIdfromCoordinates(int x, int y);
	void changeValueWithCoordinates(int x, int y, int value);

	/// 
	int sumValue(int value1, int value2);
	bool canFuse(int value1, int value2);
	bool detectCollide(Tile* tile1);
	bool canMove(int x, int y);
	void moveTile(Tile* tile);
};

