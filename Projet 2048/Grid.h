#pragma once

#include <iostream>
#include <vector>
#include "Tile.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_Z 122
#define KEY_S 115
#define KEY_Q 113
#define KEY_D 100

class Grid
{
	/* Class pour cr�er la grille et faire les diff�rentes actions dessus */
private:
	int sizeX; // taille en x de la grille 
	int sizeY; // taille en y de la grille 
	std::vector<std::vector<Tile*>> tab; // une liste dans une liste de type Tile*
	std::vector<Tile*> possibleGridPlace; // une liste de type Tile*
	std::vector<Tile*> is2048; // une liste de type Tile*

public:
	Grid(int x, int y); // constructor avec coordon�es
	Grid(int config[4][4]); // constructor avec une liste dans une liste     //# DEPRECATED
	 
	bool compare(int config[4][4]); // m�thode pour comparer un type Grid* avec une liste dans une liste     //# DEPRECATED
	bool compareVectorTile(Grid* tabCopy); // m�thode pour comparer un type Grid* avec un type Grid*

	void gridCreateCopy(Grid* tabCopy); // m�thode pour cr�er la copie d'un type Grid* depuis un type Grid*

	void searchGridPlace(); // m�thode pour enregister les cases de la grille qui sont vides (valant 0)

	void display(); // m�thode permettant d'afficher la grille de jeu

	void tileSetRandomNumber(int loop); // m�thode permettant de remplir une case random de la grille avec les chiffres 2 ou 4

	bool detectCollide(int x, int y); // m�thode pour v�rifier si une case contient d�j� un chiffre (autre que 0)
	bool canMove(int x, int y, int distX, int distY); // m�thode pour v�rifier si l'on reste toujours entre les bornes de la grilles

	void sumValue(int x, int y, int distX, int distY); // m�thode pour faire la somme de deux cases
	bool canFuse(int x, int y, int distX, int distY); // m�thode pour voir si la fusion entre deux cases est possible

	/* M�thodes pour faire les d�placements */
	void moveRight(int x);
	void moveLeft(int x);
	void moveUp(int y);
	void moveDown(int y);

	/* M�thodes pour faire les d�placements de toutes la grille */
	void moveUpSide();
	void moveDownSide();
	void moveLeftSide();
	void moveRightSide();

	/* M�thodes pour faire les fusions */
	void fusionUp(int y);
	void fusionDown(int y);
	void fusionLeft(int x);
	void fusionRight(int x);

	/* M�thodes pour faire les fusions de toutes la grilles */
	void fusionUpSide();
	void fusionDownSide();
	void fusionLeftSide();
	void fusionRightSide();

	/* M�thodes pour faire les d�placements et les fusions de toutes la grille */
	void up();
	void down();
	void left();
	void right();

	/* M�thodes pour faire les d�placements et les fusions de toutes la grille et placement un nouveau chiffre al�atoirement */
	void playRight();
	void playLeft();
	void playUp();
	void playDown();


	bool conditionGameWin(); // m�thode pour les conditions de win
	bool conditionGameLose(); // m�thode pour les conditions de lose
};