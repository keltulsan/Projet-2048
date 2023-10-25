//inclusion
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include "Grid.h"
#include "Tile.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_Z 122
#define KEY_S 115
#define KEY_Q 113
#define KEY_D 100

Grid::Grid(int x, int y) { //créer la grille
	this->sizeX = x;
	this->sizeY = y;
	this->sizeMax = this->sizeX * this->sizeY;

	this->tab.resize(this->sizeY);
	for (int i = 0; i < this->sizeY; ++i) {
		
		for (int j = 0; j < this->sizeX; ++j) 
		{
			Tile* tile = new Tile(0);
			this->tab[i].push_back(tile);
		}
	};
};

void Grid::display() { //affichage de la grille
	std::cout << "\n";
	for (int i = 0; i < this->sizeY; i++) {
		std::cout << " | ";
		for (int j = 0; j < this->sizeX; j++) {
			std::cout << this->tab[i][j]->getValue() << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
};

void Grid::changeValueWithCoordinates(int x, int y, int value) { //Change la valeur des coordonée quand un blocs se deplace
	this->tab[x][y]->setValue(value);
	this->display();
};

void Grid::sumValue(int x, int y, int distX, int distY) { //additioner tous blocs
	int newValue = this->tab[x][y]->getValue() + this->tab [x + distX] [y + distY]->getValue();
	this->tab[x + distX][y + distY]->setValue(newValue);
	this->tab[x][y]->setValue(0);
};

bool Grid::canFuse(int x, int y, int distX, int distY) { //pouvons nous fusionner ? 
	if (this->tab[x][y]->getValue() == this->tab[x + distX][y + distY]->getValue()) {
		return true;
	}
	else {
		return false;
	};
};

bool Grid::detectCollide(int x, int y) {
	if (this->tab[x][y]->getValue() != 0) {
		return true;
	}
	return false;
};

bool Grid::canMove(int x, int y, int distX, int distY) { //possbilité de bouger les blocs avec distance {-1, 1}
	if (x + distX < 0  || y + distY < 0 || x + distX > (this->sizeY - 1) || y + distY > (this->sizeX - 1)) {
		// Vérification que l'emplacement des cases après mouvement est toujours compris dans notre grille
		return false;
	}
	return true;
};

void Grid::moveTile(int x, int y, std::vector<int> movement) { //deplacer les tuile/block

	int distX = movement[0];
	int distY = movement[1];

	while (this->canMove(x, y, distX, distY)) {
		std::cout << distX << "/" << distY << std::endl;
		if (this->detectCollide(x + distX, y + distY)) {
			std::cout << "collide" << std::endl;
			if (this->canFuse(x, y, distX, distY)) {
				std::cout << "fused" << std::endl;
				this->sumValue(x, y, distX, distY);
			}
		}
		else
		{
			this->tab[x + distX][y + distY]->setValue(this->tab[x][y]->getValue());
			this->tab[x][y]->setValue(0);
		}

		if (distX > 0) {
			x++;
		}
		else if (distX < 0) {
			x--;
		}
		if (distY > 0) {
			y++;
		}
		else if (distY < 0) {
			y--;
		}


		this->display();

	};
};

//void Grid::randTuiles(nit x, int y) {
	//if this->tab[i]->getValue(){
		//Tuile = rand() _tuile1;
		//return();
	//}
	//else
		//if
//}

std::vector<int> Grid::movement() {
	std::vector<int> distance;

	while (1) {
		int keyValue = _getch();

		if (KEY_UP == keyValue || KEY_Z == keyValue) {
			//key up
			distance.push_back(-1); // x
			distance.push_back(0); // y
			return distance;
		}

		else if (KEY_DOWN == keyValue || KEY_S == keyValue) {
			// key down
			distance.push_back(1); // x
			distance.push_back(0); // y
			return distance;
		}

		else if (KEY_LEFT == keyValue || KEY_Q == keyValue) {
			// key left
			distance.push_back(0); // x
			distance.push_back(-1); // y
			return distance;
		}

		else if (KEY_RIGHT == keyValue || KEY_D == keyValue) {
			// key right
			distance.push_back(0); // x
			distance.push_back(1); // y
			return distance;
		}
	}
};