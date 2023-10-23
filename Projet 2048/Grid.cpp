#include <iostream>
#include <vector>
#include "Grid.h"
#include "Tile.h"


Grid::Grid(int x, int y) {
	this->sizeX = x;
	this->sizeY = y;
	this->sizeMax = this->sizeX * this->sizeY;
	for (int i = 0; i < this->sizeY; i++) {
		for (int j = 0; j < this->sizeX; j++) {
			this->tab.push_back(new Tile(0));
		}
	}
};

void Grid::display() {
	for (int i = 0; i < this->sizeMax; i++) {
		if (i % this->sizeY == 0 && i != 0)
		{
			std::cout << " | \n";
		}
		std::cout << " | "  << this->tab[i]->getValue() ;
	}
	std::cout << " | \n\n";
};

int Grid::getIdfromCoordinates(int x, int y) {
	int id = (x - 1) * this->sizeX + y;
	return id;
};

void Grid::changeValueWithCoordinates(int x, int y, int value) {
	int id = this->getIdfromCoordinates(x, y);
	this->tab[id - 1]->setValue(value);
	this->display();
};


int Grid::sumValue(int value1, int value2) {
	return value1 + value2;
};

bool Grid::canFuse(int value1, int value2) {
	if (value1 == value2) {
		return true;
	}
	else {
		return false;
	};
}


bool Grid::detectCollide(int x1, int x2, int y1, int y2) {
	std::vector<int> _tile1 = { x1, y1 };
	std::vector<int> _tile2 = { x2, y2 };
	if (_tile1[0] == _tile2[0] && _tile1[1] == _tile2[1]) {
		return true;
	}
	return false;
};

bool Grid::canMove(int x, int y) {
	int id = this->getIdfromCoordinates(x, y);
	if (id - 1 < 1 || id + 1 > this->sizeMax)
	return true;
};


//void Grid::moveTile(Tile* tile1) {
//	if (tile1->detectCollide(this)) {
//		if (tile1->canFuse(this)) {
//			int sum = this->sumValue(tile1->value, this->value);
//			std::cout << "fused";
//		}
//		else {
//			return;
//		}
//	}
//	else {
//		this->moveTile(this);
//	}
//
//};
