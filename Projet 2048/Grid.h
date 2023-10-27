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
	std::vector<Tile*> possibleGridPlace;
	std::vector<Tile*> is2048;

public:
	Grid(int x, int y);

	Grid(int config[4][4]);
	bool compare(int config[4][4]);

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();


	void display();
	void changeValueWithCoordinates(int x, int y, int value); // #DEPRECATED
	void tileSetRandomNumber(int loop);
	void sumValue(int x, int y, int distX, int distY);
	void movement(int x, int y, int distX, int distY);
	void moveTile(std::vector<int> movement);
	void searchGridPlace();
	void game();
	int getIdByCoordinates(int x, int y); // #DEPRECATED
	bool fusion(int x, int y, int distX, int distY);
	bool canFuse(int x, int y, int distX, int distY);
	bool detectCollide(int x, int y);
	bool canMove(int x, int y, int distX, int distY);
	bool conditionGameWin();
	bool conditionGameLoose();
	std::vector<int> controllers();
	Point getCoordinatesById(int id); // #DEPRECATED
};