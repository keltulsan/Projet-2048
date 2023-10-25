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
	std::vector<std::vector<Tile*>> tab;

public:
	Grid(int x, int y);

	void display();
	void changeValueWithCoordinates(int x, int y, int value);

	void sumValue(int x, int y, int distX, int distY);
	bool canFuse(int x, int y, int distX, int distY);
	bool detectCollide(int x, int y);
	bool canMove(int x, int y, int distX, int distY);
	void moveTile(int x, int y, std::vector<int> movement);
	std::vector<int> movement();
};