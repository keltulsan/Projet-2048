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

	void sumValue(int id, int newId);
	bool canFuse(int id, int newId);
	bool detectCollide(int id, int newId);
	bool canMove(int id, int newId, int distance);
	void moveTile(int x, int y, int movement);
	int movement();
};

