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
//
//// #DEPRECATED
//int Grid::getIdByCoordinates(int x, int y) {
//	return x * this->sizeY + y;
//}
//
//
//// #DEPRECATED
//Point Grid::getCoordinatesById(int id) {
//	Point o_Id;
//
//	o_Id.x = 0;
//	o_Id.y = 0;
//
//	while ( id >= 0) {
//
//		if (id > this->sizeX - 1) {
//			id -= this->sizeX;
//			o_Id.x++;
//		}
//		else {
//			o_Id.y++;
//			id = -1;
//		}
//	}
//	return o_Id;
//}
//
//// #DEPRECATED
//void Grid::changeValueWithCoordinates(int x, int y, int value) { //Change la valeur des coordonée quand un blocs se deplace
//	this->tab[x][y]->setValue(value);
//	if (value == 2048) {
//		this->is2048.push_back(this->tab[x][y]);
//	}
//};
//
//
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

Grid::Grid(int config[4][4]) { //créer la grille
	this->sizeX = 4;
	this->sizeY = 4;
	this->sizeMax = this->sizeX * this->sizeY;

	this->tab.resize(this->sizeY);
	for (int i = 0; i < this->sizeY; ++i) {

		for (int j = 0; j < this->sizeX; ++j)
		{
			Tile* tile = new Tile(config[i][j]);
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
	std::cout << std::endl;
};

//void Grid::sumValue(int x, int y, int distX, int distY) { //additioner tous blocs
//	int newValue = this->tab[x][y]->getValue() + this->tab [x + distX] [y + distY]->getValue();
//	this->tab[x][y]->setValue(newValue);
//	if (newValue == 2048) {
//		this->is2048.push_back(this->tab[x][y]);
//	}
//	this->tab[x + distX][y + distY]->setValue(0);
//};
//
//bool Grid::canFuse(int x, int y, int distX, int distY) { //pouvons nous fusionner ? 
//	if (this->tab[x][y]->getValue() == this->tab[x + distX][y + distY]->getValue()) {
//		return true;
//	}
//	else {
//		return false;
//	};
//
//};

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
//
//bool Grid::fusion(int x, int y, int distX, int distY) {
//	std::cout << "Fusion function" << std::endl;
//	if (this->canFuse(x, y, distX, distY)) {
//		std::cout << "fused" << std::endl;
//		this->sumValue(x, y, distX, distY);
//		return true;
//	}
//	return false;
//}
//
//void Grid::moveTile(std::vector<int> movement) {
//	int distX = movement[0];
//	int distY = movement[1];
//	int x = 0;
//	int y = 0;
//
//	if (distY == 0) {
//		if (distX == 1)
//		{
//			y = this->sizeX;
//			x = 0;
//
//			// haut
//			for (int i = 0; i < y; i++) {
//				this->movement(x, i, distX, distY);
//			}
//		}
//
//
//		else if (distX == -1 )
//		{
//			y = this->sizeX;
//			x = this->sizeY;
//			// bas
//			for (int i = 0; i < y; i++) {
//				this->movement(x, i, distX, distY);
//			}
//		}
//
//	}
//	else if (distX == 0)
//	{
//		if (distY == 1)
//		{
//			y = 0;
//			x = this->sizeY;
//			//gauche
//			for (int i = 0; i < x; i++) {
//				this->movement(i, y, distX, distY);
//			}
//		}
//		else if (distY == -1)
//		{
//			y = this->sizeX;
//			x = this->sizeY;
//
//			//droite
//			for (int i = 0; i < x; i++) {
//				this->movement(i, y, distX, distY);
//			}
//
//		}
//	}
//
//
//}
//
//void Grid::movement(int x, int y, int distX, int distY) { //deplacer les tuile/block
//
//	bool isFused = false;
//
//	while (this->canMove(x, y, distX, distY)) 
//	{
//		std::cout << x << "/" << y << std::endl;
//		if (this->detectCollide(x + distX, y + distY)) {
//			std::cout << "collide" << std::endl;
//			if (!isFused) {
//				isFused = this->fusion(x, y, distX, distY);
//			}
//			else if (tab[x + distX][y + distY]->getValue() != 0 && tab[x][y]->getValue() == 0) {
//				
//			}
//			else
//			{
//				std::cout << tab[x + distX][y + distY]->getValue() << std::endl;
//				std::cout << tab[x][y]->getValue() << std::endl;
//
//				this->tab[x][y]->setValue(this->tab[x + distX][y + distY]->getValue());
//				this->tab[x + distX][y + distY]->setValue(0);
//			}
//		}
//		else
//		{
//			this->tab[x][y]->setValue(this->tab[x + distX][y + distY]->getValue());
//			this->tab[x + distX][y + distY]->setValue(0);
//			
//		}
//
//		if (distX > 0) {
//			x++;
//		}
//		else if (distX < 0) {
//			x--;
//		}
//		if (distY > 0) {
//			y++;
//		}
//		else if (distY < 0) {
//			y--;
//		}
//		this->display();
//	}
//	isFused = false;
//	this->display();
//}
//
//void Grid::tileSetRandomNumber(int loop) 
//{
//	for (int i = 0; i < loop; i++) 
//	{
//		int randomNumber = rand() % (this->possibleGridPlace.size() - 1); // index random parmi une liste d'adresse mémoire de tile
//		double is2048 = rand() % (2048*2048);
//		if (this->possibleGridPlace[randomNumber]->getValue() == 0)
//		{
//			if (is2048 == 0){ // 1 chance sur 2048 puissance 2 d'avoir un 2048
//				this->possibleGridPlace[randomNumber]->setValue(2048);
//				this->is2048.push_back(this->possibleGridPlace[randomNumber]);
//			}
//			else if (randomNumber < 9) {
//				this->possibleGridPlace[randomNumber]->setValue(2);
//			}	
//			else {
//				this->possibleGridPlace[randomNumber]->setValue(4);
//			}
//			this->possibleGridPlace.erase(this->possibleGridPlace.begin() + randomNumber);
//		}
//	}
//	this->display();
//};
//
//void Grid::searchGridPlace() {
//	for (int i = 0; i < this->sizeY; i++) {
//		for (int j = 0; j < this->sizeX; j++) {
//			if (this->tab[i][j]->getValue() == 0) 
//			{
//				this->possibleGridPlace.push_back(this->tab[i][j]);
//			}
//		}
//	}
//}
//
//std::vector<int> Grid::controllers() {
//
//	while (1) {
//		int keyValue = _getch();
//
//		if (KEY_UP == keyValue || KEY_Z == keyValue) {
//			//key up
//			return std::vector<int>{1, 0}; // x, y
//		}
//
//		else if (KEY_DOWN == keyValue || KEY_S == keyValue) {
//			// key down
//			return std::vector<int>{-1, 0}; // x, y
//		}
//
//		else if (KEY_LEFT == keyValue || KEY_Q == keyValue) {
//			// key left
//			return std::vector<int>{0, 1}; // x, y
//		}
//
//		else if (KEY_RIGHT == keyValue || KEY_D == keyValue) {
//			// key right
//			return std::vector<int>{0, -1}; // x, y
//		}
//
//	}
//};
//
//bool Grid::conditionGameWin() {
//	//condition de win
//	if (this->is2048.size() >= 1) {
//		return true;
//	}
//	else {
//		return false;
//	}
//};
//
//bool Grid::conditionGameLoose() {
//	//condition de lose
//	if (this->possibleGridPlace.empty()) {
//		return true;
//	}
//	else {
//		return false;
//	}
//};
//
//
//void Grid::game() {
//	this->searchGridPlace();
//	//this->tileSetRandomNumber(2);
//	this->display();
//	while (1) {
//		if (this->conditionGameLoose()) {
//			std::cout << std::endl << "You Lose :( ";
//			return;
//		}
//		else if (this->conditionGameWin()) {
//			std::cout << std::endl << "You Win !";
//			return;
//		}
//		else {
//			std::vector<int> dist = this->controllers();
//			this->movement(0, 0, dist[0], dist[1]);
//		}
//	}
//}
//

bool Grid::compare(int config[4][4])
{
	for (int i = 0; i < this->sizeY; ++i) {

		for (int j = 0; j < this->sizeX; ++j)
		{
			if (config[i][j] != this->tab[i][j]->getValue()) {
				return false;
			}

		}
	};
	return true;
}

void Grid::moveRight()
{
	int x = 0;
	int y = this->sizeX - 1;
	int offset = 0;

	for (int j = y; j >= 0; j--)
	{
		if (this->tab[x][j]->getValue() == 0)
		{
			offset--;
		}
	}
	this->tab[x][y]->setValue(this->tab[x][y + offset]->getValue());
	this->tab[x][y + offset]->setValue(0);
}

void Grid::moveLeft()
{
	int x = 0;
	int y = 0;
	int offset = 0;

	for (int j = 0; j < this->sizeY - 1; j++)
	{
		if (this->tab[x][j]->getValue() == 0)
		{
			offset++;
		}
	}
	this->tab[x][y]->setValue(this->tab[x][y + offset]->getValue());
	this->tab[x][y + offset]->setValue(0);
}

void Grid::moveUp()
{
	int x = 0;
	int y = 0;
	int offset = 0;

	for (int i = 0; i < this->sizeY - 1; i++)
	{
		if (this->tab[i][y]->getValue() == 0)
		{
			offset++;
		}
	}
	this->tab[x][y]->setValue(this->tab[x + offset][y]->getValue());
	this->tab[x + offset][y]->setValue(0);
}

void Grid::moveDown()
{
	int x = this->sizeY - 1;
	int y = 0;
	int offset = 0;

	for (int i = x; i >= 0; i--)
	{
		if (this->tab[i][y]->getValue() == 0)
		{
			offset--;
		}
	}
	this->tab[x][y]->setValue(this->tab[x + offset][y]->getValue());
	this->tab[x + offset][y]->setValue(0);
}