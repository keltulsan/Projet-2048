#include <iostream>
#include <vector>
#include "Tile.h"

Tile::Tile(int value = 0) {
	/* Constructor */
	this->value = value;
};

int Tile::getValue() {
	/* M�thode pour r�cup�rer la valeur de la case */
	return this->value;
};

void Tile::setValue(int value) {
	/* M�tohde pour modifier la valeur de la case*/
	this->value = value;
};

