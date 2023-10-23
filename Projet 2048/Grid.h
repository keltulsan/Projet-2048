#include <iostream>
#include <vector>

class Grid
{
private:
	int sizeX;
	int sizeY;
	int sizeMax;
	std::vector<int> tab;

public:
	Grid(int x, int y);

	void display();
	int getIdfromCoordinates(int x, int y);
	void changeValueWithCoordinates(int x, int y, int value);
};

