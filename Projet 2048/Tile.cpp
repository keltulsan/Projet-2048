#include <iostream>
#include <vector>
#include "Tile.h"

Tile::Tile(int value) {
	this->value = value;
};

int Tile::getValue() {
	return this->value;
};

void Tile::setValue(int value) {
	this->value = value;
};

