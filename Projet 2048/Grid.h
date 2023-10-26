#pragma once

#include <iostream>
#include <vector>
#include "Tile.h"

//#DEPRECATED
struct Point
{
	int x;
	int y;
};

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
	void tileSetRandomNumber(int loop);
	void sumValue(int x, int y, int distX, int distY);
	void moveTile(int x, int y, std::vector<int> movement);
	int getIdByCoordinates(int x, int y);
	bool canFuse(int x, int y, int distX, int distY);
	bool detectCollide(int x, int y);
	bool canMove(int x, int y, int distX, int distY);
	std::vector<int> movement();
	std::vector<Tile*> searchGridPlace(int value);
	Point getCoordinatesById(int id);
};