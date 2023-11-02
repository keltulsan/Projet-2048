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

typedef enum Actions
{
	start = 0,
	restart = 1,
	quit = 2,
	win = 3,
	lose = 4
};

class Game
{
	/* Classe pour jouer au 2048 version console */
private:
	int sizeX; // taille de la grille en x
	int sizeY; // taille de la grille en y
	bool isLoad; // bool pour v�rifier si les texture sont load
	bool isStarted; // bool pour v�rifier si la partie a commenc�
	int screenWidth; // longueur de l'�cran
	int screenHeight; // largeur de l'�cran

	int winAndLoseX; // position x des bani�res de win ou lose
	int winAndLoseY; // position y des bani�res de win ou lose
	int winAndLoseW; // dimension x des bani�res de win ou lose
	int winAndLoseH; // dimension Y des bani�res de win ou lose 

	int actionsX; // position x des case des actions possible (restart/ quit)
	int actionsY; // position y des case des actions possible (restart/ quit)
	int actionsW; // dimension x des case des actions possible (restart/ quit)
	int actionsH; // dimension y des case des actions possible (restart/ quit) 

	int gapBetweenActions; // distance entre les cases des diff�rentes actions

	SDL_Texture* imageTextures[11]; // tableau de texture pour les tiles 
	SDL_Texture* imageActions[5]; // tableau de texture pour les diff�rentes actions (win/lose/start ...)
	SDL_Texture* imageStartScreen[1]; // tableau de texture pour la page d'accueil

public :
	Game(int x, int y, int screenWidth, int screenHeight); // constructor

	void initImageTile(SDL_Renderer* renderer); // m�thode pour initialiser toutes les textures des tiles
	void initImageTexture(SDL_Renderer* renderer); // m�thode pour initialiser toutes les textures
	void destroyTextures(); // m�thode pour d�truire toutes les textures
	SDL_Texture** getTileTexture(); // m�thode qui renvoie un tableau des textures tiles
	void startGame(); // m�thode pour lancer le jeu
	void startGameGraphic(); // m�thode pour lancer le jeu version graphique
	void restartGame(); // m�thode pour relancer le jeu
	void endGameDisplay(int number, SDL_Renderer* renderer); // m�thode pour afficher le menu de fin de partie
	void startGameDisplay(SDL_Renderer* renderer); // m�thode pour afficher le menu de d�but de partie
};