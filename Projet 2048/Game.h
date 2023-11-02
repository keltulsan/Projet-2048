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
	bool isLoad; // bool pour vérifier si les texture sont load
	bool isStarted; // bool pour vérifier si la partie a commencé
	int screenWidth; // longueur de l'écran
	int screenHeight; // largeur de l'écran

	int winAndLoseX; // position x des banières de win ou lose
	int winAndLoseY; // position y des banières de win ou lose
	int winAndLoseW; // dimension x des banières de win ou lose
	int winAndLoseH; // dimension Y des banières de win ou lose 

	int actionsX; // position x des case des actions possible (restart/ quit)
	int actionsY; // position y des case des actions possible (restart/ quit)
	int actionsW; // dimension x des case des actions possible (restart/ quit)
	int actionsH; // dimension y des case des actions possible (restart/ quit) 

	int gapBetweenActions; // distance entre les cases des différentes actions

	SDL_Texture* imageTextures[11]; // tableau de texture pour les tiles 
	SDL_Texture* imageActions[5]; // tableau de texture pour les différentes actions (win/lose/start ...)
	SDL_Texture* imageStartScreen[1]; // tableau de texture pour la page d'accueil

public :
	Game(int x, int y, int screenWidth, int screenHeight); // constructor

	void initImageTile(SDL_Renderer* renderer); // méthode pour initialiser toutes les textures des tiles
	void initImageTexture(SDL_Renderer* renderer); // méthode pour initialiser toutes les textures
	void destroyTextures(); // méthode pour détruire toutes les textures
	SDL_Texture** getTileTexture(); // méthode qui renvoie un tableau des textures tiles
	void startGame(); // méthode pour lancer le jeu
	void startGameGraphic(); // méthode pour lancer le jeu version graphique
	void restartGame(); // méthode pour relancer le jeu
	void endGameDisplay(int number, SDL_Renderer* renderer); // méthode pour afficher le menu de fin de partie
	void startGameDisplay(SDL_Renderer* renderer); // méthode pour afficher le menu de début de partie
};