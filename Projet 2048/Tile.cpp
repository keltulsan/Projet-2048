#include <iostream>
#include <vector>
#include "Tile.h"

Tile::Tile(int value = 0) {
	/* Constructor */
	this->value = value;
};

int Tile::getValue() {
	/* Méthode pour récupérer la valeur de la case */
	return this->value;
};

void Tile::setValue(int value) {
	/* Métohde pour modifier la valeur de la case*/
	this->value = value;
};

