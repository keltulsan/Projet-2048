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
//void Grid::changeValueWithCoordinates(int x, int y, int value) { //Change la valeur des coordon�e quand un blocs se deplace
//	this->tab[x][y]->setValue(value);
//	if (value == 2048) {
//		this->is2048.push_back(this->tab[x][y]);
//	}
//};
//
//
Grid::Grid(int x, int y) { //cr�er la grille
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

Grid::Grid(int config[4][4]) { //cr�er la grille
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
    int maxSize = log10(4 * pow(2, (this->sizeX * this->sizeY))) - .5f; // size maximale que prendra la taille d'une box par rapport � la taille de la grille

	/* Initialisation des variables ensuite affich�e */
    std::string preString = " ";
    std::string verticalSeperation = " | ";
    std::string horizontalSeperation = "  ";

	// init de l'affichage au dessus des box
    for (int i = 0; i < (maxSize + 4) * this->sizeX - 1; i++)
    {
        horizontalSeperation += "-";
    }

	// init de l'affichage � l'int�rieur des box hors la ligne qui contient les chiffres
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

		// affichage des espaces vides � l'int�rieur de la box
        for (int k = 0; k < ((maxSize + .5f) / 2 - .5f) / 2; k++)
        {
			std::cout << std::endl << horizontalEmptySeperation;
        }
		std::cout << std::endl << verticalSeperation;

		// affichage de ligne comprenant le nombre
        for (int i = 0; i < this->sizeX; i++)
        {
            int len = (maxSize - (this->tab[j][i]->getValue() == 0 ? 1 : log10(this->tab[j][i]->getValue()))); // calcule permettant de r�cup�rer la longueur de la box sans la taille du chiffre
            
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

		// affichage des espaces vides � l'int�rieur de la box
        for (int k = 0; k < ((maxSize + .5f) / 2 - .5f) / 2; k++)
        {
			std::cout << std::endl << horizontalEmptySeperation;
        }
    }

	// affichage de la ligne du bas de la grille
	std::cout << std::endl << horizontalSeperation;
	std::cout << std::endl;
};

void Grid::sumValue(int x, int y, int distX, int distY) { //additioner tous blocs
	int newValue = this->tab[x][y]->getValue() + this->tab [x + distX] [y + distY]->getValue();
	this->tab[x][y]->setValue(newValue);
	if (newValue == 2048) {
		this->is2048.push_back(this->tab[x][y]);
	}
	this->tab[x + distX][y + distY]->setValue(0);
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

bool Grid::canMove(int x, int y, int distX, int distY) { //possbilit� de bouger les blocs avec distance {-1, 1}
	if (x + distX < 0  || y + distY < 0 || x + distX > (this->sizeY - 1) || y + distY > (this->sizeX - 1)) {
		// V�rification que l'emplacement des cases apr�s mouvement est toujours compris dans notre grille
		return false;
	}
	return true;
};

bool Grid::fusion(int x, int y, int distX, int distY) {
	std::cout << "Fusion function" << std::endl;
	if (this->canFuse(x, y, distX, distY)) {
		std::cout << "fused" << std::endl;
		this->sumValue(x, y, distX, distY);
		return true;
	}
	return false;
}

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
//		int randomNumber = rand() % (this->possibleGridPlace.size() - 1); // index random parmi une liste d'adresse m�moire de tile
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
std::string Grid::controllers() {

	while (1) {
		int keyValue = _getch();

		if (KEY_UP == keyValue || KEY_Z == keyValue) {
			//key up
			return "Up";
		}

		else if (KEY_DOWN == keyValue || KEY_S == keyValue) {
			// key down
			return "Down";
		}

		else if (KEY_LEFT == keyValue || KEY_Q == keyValue) {
			// key left
			return "Left";
		}

		else if (KEY_RIGHT == keyValue || KEY_D == keyValue) {
			// key right
			return "Right";
		}

	}
};

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

void Grid::moveRight(int x)
{
	/* Permet de faire un mouvement vers la droite */

	int y = this->sizeX - 1;
	int offset = 0;
	int realOffset = 0;

	while (1)
	{
		for (int j = y; j >= 0; j--)  // boucle qui regarde les valeurs de notre grille
		{
			if (y <= 0)
			{
				// v�rifie si nous sommes toujours dans la grille de jeu
				return;
			}
			else if (this->tab[x][j]->getValue() == 0)
			{
				// ajoute une distance depuis laquelle devra se d�placer la case
				offset--;
			}
			else if (this->tab[x][j]->getValue() != 0 && offset == 0)
			{
				// permet d'incr�mente x si la case choisie est d�j� un chiffre et que l'on a pas besoin de le d�placer
				y--;
			}
			else if (this->tab[x][j]->getValue() != 0 && realOffset == 0)
			{
				// permet de sauvegarder la bonne distance n�c�ssaire entre la case et le nombre de case avant
				realOffset = offset;
			}
		}
		// permet d'intervertir les cases
		this->tab[x][y]->setValue(this->tab[x][y + realOffset]->getValue());
		this->tab[x][y + realOffset]->setValue(0);

		y--; // incr�mente x dans le cas o� l'on vient de modifier l'une des case
		offset = 0;
		realOffset = 0;
	}

}

void Grid::moveLeft(int x)
{
	/* Permet de faire un mouvement vers la gauche */

	int y = 0;
	int offset = 0;
	int realOffset = 0;

	while (1)
	{
		for (int j = y; j <= this->sizeX - 1; j++)
		{
			if (y >= this->sizeX - 1)
			{
				// v�rifie si nous sommes toujours dans la grille de jeu
				return;
			}
			else if (this->tab[x][j]->getValue() == 0)
			{
				// ajoute une distance depuis laquelle devra se d�placer la case
				offset++;
			}
			else if (this->tab[x][j]->getValue() != 0 && offset == 0)
			{
				// permet d'incr�mente x si la case choisie est d�j� un chiffre et que l'on a pas besoin de le d�placer
				y++;
			}
			else if (realOffset == 0 && this->tab[x][j]->getValue() != 0)
			{
				// permet de sauvegarder la bonne distance n�c�ssaire entre la case et le nombre de case avant
				realOffset = offset;
			}
		}
		// permet d'intervertir les cases
		this->tab[x][y]->setValue(this->tab[x][y + realOffset]->getValue());
		this->tab[x][y + realOffset]->setValue(0);

		y++; // incr�mente x dans le cas o� l'on vient de modifier l'une des case
		offset = 0;
		realOffset = 0;
	}
}

void Grid::moveUp(int y)
{
	/* Permet de faire un mouvement vers le haut */

	int x = 0;
	int offset = 0;
	int realOffset = 0;

	while (1)
	{
		for (int i = x; i <= this->sizeY - 1; i++)  // boucle qui regarde les valeurs de notre grille
		{
			if (x >= this->sizeY - 1)
			{
				// v�rifie si nous sommes toujours dans la grille de jeu
				return;
			}
			else if (this->tab[i][y]->getValue() == 0)
			{
				// ajoute une distance depuis laquelle devra se d�placer la case
				offset++;
			}
			else if (this->tab[i][y]->getValue() != 0 && offset == 0)
			{
				// permet d'incr�mente x si la case choisie est d�j� un chiffre et que l'on a pas besoin de le d�placer
				x++;
			}
			else if (realOffset == 0 && this->tab[i][y]->getValue() != 0)
			{
				// permet de sauvegarder la bonne distance n�c�ssaire entre la case et le nombre de case avant
				realOffset = offset;
			}
		}
		// permet d'intervertir les cases
		this->tab[x][y]->setValue(this->tab[x + realOffset][y]->getValue());
		this->tab[x + realOffset][y]->setValue(0);

		x++; // incr�mente x dans le cas o� l'on vient de modifier l'une des case
		offset = 0;
		realOffset = 0;
	}
}

void Grid::moveDown(int y)
{
	/* Permet de faire un mouvement vers le bas */

	int x = this->sizeY - 1;
	int offset = 0;
	int realOffset = 0;

	while (1)
	{
		for (int i = x; i >= 0; i--)  // boucle qui regarde les valeurs de notre grille
		{
			if (x <= 0)
			{
				// v�rifie si nous sommes toujours dans la grille de jeu
				return;
			}
			else if (this->tab[i][y]->getValue() == 0)
			{
				// ajoute une distance depuis laquelle devra se d�placer la case
				offset--;
			}
			else if (this->tab[i][y]->getValue() != 0 && offset == 0)
			{
				// permet d'incr�mente x si la case choisie est d�j� un chiffre et que l'on a pas besoin de le d�placer
				x--;
			}
			else if (this->tab[i][y]->getValue() != 0 && realOffset == 0)
			{
				// permet de sauvegarder la bonne distance n�c�ssaire entre la case et le nombre de case avant
				realOffset = offset;
			}
		}
		// permet d'intervertir les cases
		this->tab[x][y]->setValue(this->tab[x + realOffset][y]->getValue());
		this->tab[x + realOffset][y]->setValue(0);

		x--; // incr�mente x dans le cas o� l'on vient de modifier l'une des case
		offset = 0;
		realOffset = 0;
	}
}


void Grid::moveRightSide()
{
	for (int i = 0; i < this->sizeY; i++) 
	{
		this->moveRight(i);
	}
}

void Grid::moveLeftSide()
{
	for (int i = 0; i < this->sizeY; i++)
	{
		this->moveLeft(i);
	}
}

void Grid::moveUpSide()
{
	for (int j = 0; j < this->sizeY; j++)
	{
		this->moveUp(j);
	}
}

void Grid::moveDownSide()
{
	for (int j = 0; j < this->sizeY; j++)
	{
		this->moveDown(j);
	}
}