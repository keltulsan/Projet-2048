//inclusion
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include "Grid.h"
#include "Tile.h"

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

void Grid::gridCreateCopy(Grid* tabCopy) { //cr�er une copy de la grille 
	for (int i = 0; i < this->sizeY; ++i) {

		for (int j = 0; j < this->sizeX; ++j)
		{
			tabCopy->tab[i][j]->getValue();
			this->tab[i][j]->setValue(tabCopy->tab[i][j]->getValue());
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
			for (int k = 0; k < (len - .5f) /2; k++)
            {
				std::cout << preString;
            }
			std::cout << this->tab[j][i]->getValue();
            for (int k = 0; k < (len + .5f) / 2; k++)
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
	this->possibleGridPlace.push_back(this->tab[x + distX][y + distY]);
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


void Grid::tileSetRandomNumber(int loop) 
{
	this->possibleGridPlace = {}; // initialise les cases jouables � une liste vide
	this->searchGridPlace(); // recherche les cases jouables

	for (int i = 0; i < loop; i++) 
	{
		int randomNumber = rand() % (this->possibleGridPlace.size()); // index random parmi une liste d'adresse m�moire de tile
		double is2048 = rand() % (2048*2048);
		if (this->possibleGridPlace[randomNumber]->getValue() == 0)
		{
			if (is2048 == 0){ // 1 chance sur 2048 puissance 2 d'avoir un 2048
				this->possibleGridPlace[randomNumber]->setValue(2048);
				this->is2048.push_back(this->possibleGridPlace[randomNumber]);
			}
			else if (randomNumber < 9) {
				this->possibleGridPlace[randomNumber]->setValue(2);
			}	
			else {
				this->possibleGridPlace[randomNumber]->setValue(4);
			}
			this->possibleGridPlace.erase(this->possibleGridPlace.begin() + randomNumber);
		}
	}
	this->display();
};

void Grid::searchGridPlace() {

	for (int i = 0; i < this->sizeY; i++) {
		for (int j = 0; j < this->sizeX; j++) {
			if (this->tab[i][j]->getValue() == 0) 
			{
				this->possibleGridPlace.push_back(this->tab[i][j]);
			}
		}
	}
}

void Grid::controllers() {

	while (1) {
		int keyValue = _getch();

		if (KEY_UP == keyValue || KEY_Z == keyValue) {
			//key up
			this->up();
			this->tileSetRandomNumber(1);
		}

		else if (KEY_DOWN == keyValue || KEY_S == keyValue) {
			// key down
			this->down();
			this->tileSetRandomNumber(1);
		}

		else if (KEY_LEFT == keyValue || KEY_Q == keyValue) {
			// key left
			this->left();
			this->tileSetRandomNumber(1);
		}

		else if (KEY_RIGHT == keyValue || KEY_D == keyValue) {
			// key right
			this->right();
			this->tileSetRandomNumber(1);
		}

	}
};

bool Grid::conditionGameWin() {
	//condition de win
	if (this->is2048.size() >= 1) {
		return true;
	}
	else {
		return false;
	}
};

bool Grid::conditionGameLose() {
	Grid* tabCopy = new Grid(this->sizeX, this->sizeY);
	//condition de lose
	if (this->possibleGridPlace.empty()) {
		tabCopy->gridCreateCopy(this);
		tabCopy->right();
		tabCopy->left();
		tabCopy->up();
		tabCopy->down();
		if (this->compareVectorTile(tabCopy))
		{
			delete tabCopy;
			std::cout << true;
			return true;
		}
	}
	return false;
}


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

bool Grid::compareVectorTile(Grid* tabCopy)
{
	for (int i = 0; i < this->sizeY; ++i) {

		for (int j = 0; j < this->sizeX; ++j)
		{
			if (tabCopy->tab[i][j]->getValue() != this->tab[i][j]->getValue()) {
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
				// permet d'incr�mente y si la case choisie est d�j� un chiffre et que l'on a pas besoin de le d�placer
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
		for (int j = y; j <= (this->sizeX - 1); j++)
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
				// permet d'incr�mente y si la case choisie est d�j� un chiffre et que l'on a pas besoin de le d�placer
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
		for (int i = x; i <= (this->sizeY - 1); i++)  // boucle qui regarde les valeurs de notre grille
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
	/* Permet de faire les d�placement des cases vers la droite */
	for (int i = 0; i < this->sizeY; i++) 
	{
		this->moveRight(i);
	}
}

void Grid::moveLeftSide()
{
	/* Permet de faire les d�placement des cases vers la gauche */
	for (int i = 0; i < this->sizeY; i++)
	{
		this->moveLeft(i);
	}
}

void Grid::moveUpSide()
{
	/* Permet de faire les d�placement des cases vers le haut */
	for (int j = 0; j < this->sizeX; j++)
	{
		this->moveUp(j);
	}
}

void Grid::moveDownSide()
{
	/* Permet de faire les d�placement des cases vers le bas */
	for (int j = 0; j < this->sizeX; j++)
	{
		this->moveDown(j);
	}
}

void Grid::fusionRight(int x)
{
	/* Permet de faire la fusion des cases d'une colonne vers du cot� droit */
	for (int j = this->sizeX - 1; j > 0 ; j--)
	{
		if (this->canMove(x, j, 0, -1))
		{
			if (this->canFuse(x, j, 0, -1))
			{
				this->sumValue(x, j, 0, -1);
				return;
			}
		}
	}
}

void Grid::fusionLeft(int x)
{
	/* Permet de faire la fusion des cases d'une colonne vers du cot� gauche */
	for (int j = 0; j < this->sizeX; j++)
	{
		if (this->canMove(x, j, 0, 1))
		{
			if (this->canFuse(x, j, 0, 1))
			{
				this->sumValue(x, j, 0, 1);
				return;
			}
		}
	}
}

void Grid::fusionUp(int y)
{
	/* Permet de faire la fusion des cases d'une colonne vers du haut */
	for (int i = 0; i < this->sizeY; i++)
	{
		if (this->canMove(i, y, 1, 0))
		{
			if (this->canFuse(i, y, 1, 0))
			{
				this->sumValue(i, y, 1, 0);
				return;
			}
		}
	}
}

void Grid::fusionDown(int y)
{
	/* Permet de faire la fusion des cases d'une colonne vers du bas */
	for (int i = this->sizeY - 1; i > 0; i--)
	{
		if (this->canMove(i, y, -1, 0))
		{
			if (this->canFuse(i, y, -1, 0))
			{
				this->sumValue(i, y, -1, 0);
				return;
			}
		}

	}
}

void Grid::fusionRightSide()
{
	/* Permet de faire la fusion des cases vers du cot� droit */
	for (int i = 0; i < this->sizeY; i++)
	{
		this->fusionRight(i);
	}
}

void Grid::fusionLeftSide()
{
	/* Permet de faire la fusion des cases vers du cot� gauche */
	for (int i = 0; i < this->sizeY; i++)
	{
		this->fusionLeft(i);
	}
}

void Grid::fusionUpSide()
{
	/* Permet de faire la fusion des cases vers du haut */
	for (int j = 0; j < this->sizeX; j++)
	{
		this->fusionUp(j);
	}
}

void Grid::fusionDownSide()
{
	/* Permet de faire la fusion des cases vers du bas */
	for (int j = 0; j < this->sizeX; j++)
	{
		this->fusionDown(j);
	}
}


void Grid::right()
{
	/* Permet de r�aliser le mouvement vers la droite */
	this->moveRightSide();
	this->fusionRightSide();
	this->moveRightSide();
}

void Grid::left()
{
	/* Permet de r�aliser le mouvement vers la gauche */
	this->moveLeftSide();
	this->fusionLeftSide();
	this->moveLeftSide();
}

void Grid::up()
{
	/* Permet de r�aliser le mouvement vers le haut */
	this->moveUpSide();
	this->fusionUpSide();
	this->moveUpSide();
}

void Grid::down()
{
	/* Permet de r�aliser le mouvement vers le bas */
	this->moveDownSide();
	this->fusionDownSide();
	this->moveDownSide();
}

void Grid::playRight()
{
	Grid* gridCopy = new Grid(this->sizeX, this->sizeY);
	gridCopy->gridCreateCopy(this);
	this->right();
	if (!(gridCopy->compareVectorTile(this)))
	{
		this->tileSetRandomNumber(1);
	}
};

void Grid::playLeft()
{
	Grid* gridCopy = new Grid(this->sizeX, this->sizeY);
	gridCopy->gridCreateCopy(this);
	this->left();
	if (!(gridCopy->compareVectorTile(this)))
	{
		this->tileSetRandomNumber(1);
	}
};

void Grid::playUp()
{
	Grid* gridCopy = new Grid(this->sizeX, this->sizeY);
	gridCopy->gridCreateCopy(this);
	this->up();
	if (!(gridCopy->compareVectorTile(this)))
	{
		this->tileSetRandomNumber(1);
	}
};

void Grid::playDown()
{
	Grid* gridCopy = new Grid(this->sizeX, this->sizeY);
	gridCopy->gridCreateCopy(this);
	this->down();
	if (!(gridCopy->compareVectorTile(this)))
	{
		this->tileSetRandomNumber(1);
	}
};