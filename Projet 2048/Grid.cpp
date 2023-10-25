//inclusion
#include <iostream>
#include <vector>
#include <string>
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
	 //system("CLS");
    int maxSize = log10(4 * pow(2, (this->sizeX * this->sizeY))) - .5f; // size maximale que prendra la taille d'une box par rapport à la taille de la grille

	/* Initialisation des variables ensuite affichée */
    std::string preString = " ";
    std::string verticalSeperation = " | ";
    std::string horizontalSeperation = "  ";

	// init de l'affichage au dessus des box
    for (int i = 0; i < (maxSize + 4) * this->sizeX - 1; i++)
    {
        horizontalSeperation += "-";
    }

	// init de l'affichage à l'intérieur des box hors la ligne qui contient les chiffres
    std::string horizontalEmptySeperation = verticalSeperation;
    for (int i = 0; i < this->sizeX; i++)
    {
        for (int i = 0; i < maxSize +1; i++)
        {
            horizontalEmptySeperation += preString;
        }
        horizontalEmptySeperation += verticalSeperation;
    }

	/* Affichage de la grille de jeu */
    for (int j = 0; j < this->sizeY; j++)
    {
		std::cout << std::endl << horizontalSeperation;

		// affichage des espaces vides à l'intérieur de la box
        for (int k = 0; k < ((maxSize + .5f) / 2 - .5f) / 2; k++)
        {
			std::cout << std::endl << horizontalEmptySeperation;
        }
		std::cout << std::endl << verticalSeperation;

		// affichage de ligne comprenant le nombre
        for (int i = 0; i < this->sizeX; i++)
        {
            int len = (maxSize - (this->tab[j][i]->getValue() == 0 ? 1 : log10(this->tab[j][i]->getValue()))); // calcule permettant de récupérer la longueur de la box sans la taille du chiffre
            
			/* Affichage du nombre au centre droit de la box */
			for (int k = 0; k < (len + .5f) /2; k++)
            {
				std::cout << preString;
            }
			std::cout << this->tab[j][i]->getValue();
            for (int k = 0; k < (len - .5f) / 2; k++)
            {
				std::cout << preString;
            }
			std::cout << verticalSeperation;
        }

		// affichage des espaces vides à l'intérieur de la box
        for (int k = 0; k < ((maxSize + .5f) / 2 - .5f) / 2; k++)
        {
			std::cout << std::endl << horizontalEmptySeperation;
        }
    }

	// affichage de la ligne du bas de la grille
	std::cout << std::endl << horizontalSeperation;
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

	while (1) {
		int keyValue = _getch();

		if (KEY_UP == keyValue || KEY_Z == keyValue) {
			//key up
			return std::vector<int>{-1, 0}; // x, y
		}

		else if (KEY_DOWN == keyValue || KEY_S == keyValue) {
			// key down
			return std::vector<int>{1, 0}; // x, y
		}

		else if (KEY_LEFT == keyValue || KEY_Q == keyValue) {
			// key left
			return std::vector<int>{0, -1}; // x, y
		}

		else if (KEY_RIGHT == keyValue || KEY_D == keyValue) {
			// key right
			return std::vector<int>{0, 1}; // x, y
		}

	}
};