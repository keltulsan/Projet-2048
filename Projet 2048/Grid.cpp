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


Grid::Grid(int x, int y) { //cree la grille
	this->sizeX = x; 
	this->sizeY = y; 
	this->sizeMax = this->sizeX * this->sizeY; 
	for (int i = 0; i < this->sizeY; i++) { 
		for (int j = 0; j < this->sizeX; j++) { 
			this->tab.push_back(new Tile(0));
		}
	}
};

void Grid::display() { //affichage de la grille
	std::cout << "\n";
	for (int i = 0; i < this->sizeMax; i++) {
		if (i % this->sizeY == 0 && i != 0)
		{
			std::cout << " | \n";
		}
		std::cout << " | "  << this->tab[i]->getValue() ;
	}
	std::cout << " | \n\n";
};

int Grid::getIdfromCoordinates(int x, int y) { //recupérer les coordonées 
	int id = (x - 1) * this->sizeX + y;
	return id;
};

void Grid::changeValueWithCoordinates(int x, int y, int value) { //Change la valeur des coordonée quand un blocs se deplace
	int id = this->getIdfromCoordinates(x, y);
	this->tab[id - 1]->setValue(value);
	this->display();
};


void Grid::sumValue(int id, int newId) { //additioner tous blocs
	int newValue = this->tab[id]->getValue() + this->tab[newId]->getValue();
	this->tab[newId]->setValue(newValue);
	this->tab[id]->setValue(0);
};


bool Grid::canFuse(int id, int newId) { //pouvons nous fusionner ? 
	if (this->tab[id]->getValue() == this->tab[newId]->getValue()) {
		return true;
	}
	else {
		return false;
	};
}


bool Grid::detectCollide(int id, int newId) {
	if (this->tab[newId]->getValue() != 0) {
		return true;
	}
	return false;
};

bool Grid::canMove(int id, int newId, int distance) { //possbilité de bouger les blocs avec distance {-1, 1}
	id++; // ++ car envoie d'un id pour un tableau et non l'id des cases créées
	newId++; // ++ car envoie d'un id pour un tableau et non l'id des cases créées
	if (newId < 1  || newId > this->sizeMax || id % this->sizeY == 0 && distance == 1 || id % this->sizeY + 1 == 0 && distance == -1) {
		// Verifie que l'id reste dans les bornes de la grille
		// vérifie que l'id reste à droite et ne dépasse pas de la grille
		// vérifie que l'id reste à gauche et ne dépasse pas de la grille
		return false;
	}
	return true;
};

//void Grid::randTuiles(int x, int y) {
	//if this->tab[i]->getValue(){
		//Tuile = rand() _tuile1;
		//return();
	//}
	//else
		//if
//}



void Grid::moveTile(int x , int y, int movement) { //deplacer les tuile/block
	int id = this->getIdfromCoordinates(x, y) - 1;
	int newId = id + movement;
	if (this->canMove(id, newId, movement)) {
		if (this->detectCollide(id, newId)) {
			if (this->canFuse(id, newId)) {
				this->sumValue(id, newId);
			}
		}
		else {
			this->tab[newId]->setValue(this->tab[id]->getValue());
			this->tab[id]->setValue(0);
		}
		//system("CLS");
		this->display();
	}
};


int Grid::movement() {
	while (1) {
		int keyValue = _getch();

		if (KEY_UP == keyValue || KEY_Z == keyValue) {
			return -this->sizeX;   //key up
		}

		else if (KEY_DOWN == keyValue || KEY_S == keyValue) {
			return this->sizeX;   // key down
		}

		else if (KEY_LEFT == keyValue || KEY_Q == keyValue) {
			return -1;  // key left
		}

		else if (KEY_RIGHT == keyValue || KEY_D == keyValue) {
			return 1;  // key right
		}

	}
};
