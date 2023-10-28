#pragma once

#include <iostream>
#include <vector>
#include "Tile.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_Z 122
#define KEY_S 115
#define KEY_Q 113
#define KEY_D 100

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
	bool compareVectorTile(Grid* tabCopy);

	void moveRight(int x);
	void moveLeft(int x);
	void moveUp(int y);
	void moveDown(int y);
	void moveUpSide();
	void moveDownSide();
	void moveLeftSide();
	void moveRightSide();


	void fusionUp(int y);
	void fusionDown(int y);
	void fusionLeft(int x);
	void fusionRight(int x);

	void fusionUpSide();
	void fusionDownSide();
	void fusionLeftSide();
	void fusionRightSide();

	void up();
	void down();
	void left();
	void right();

	void playRight();
	void playLeft();
	void playUp();
	void playDown();

	void gridCreateCopy(Grid* tabCopy);



	void display();
	void changeValueWithCoordinates(int x, int y, int value); // #DEPRECATED
	void tileSetRandomNumber(int loop);
	void sumValue(int x, int y, int distX, int distY);
	void movement(int x, int y, int distX, int distY);
	void moveTile(std::vector<int> movement);
	void searchGridPlace();
	int getIdByCoordinates(int x, int y); // #DEPRECATED
	bool fusion(int x, int y, int distX, int distY);
	bool canFuse(int x, int y, int distX, int distY);
	bool detectCollide(int x, int y);
	bool canMove(int x, int y, int distX, int distY);
	bool conditionGameWin();
	bool conditionGameLose();
	void controllers();
	Point getCoordinatesById(int id); // #DEPRECATED
};