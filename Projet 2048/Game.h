#pragma once

#include "Grid.h"
#include "Window.h"

/* Define de code pour chaque touche */
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_Z 122
#define KEY_S 115
#define KEY_Q 113
#define KEY_D 100

class Game
{
	/* Classe pour jouer au 2048 version console */
private:
	int sizeX; // taille de la grille en x
	int sizeY; // taille de la grille en y

public :
	Game(int x, int y); // constructor

	void startGame(); // méthode pour lancer le jeu
	void startGameGraphic(); // méthode pour lancer le jeu version graphique
	void restartGame(); // méthode pour relancer le jeu
};