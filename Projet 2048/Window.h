#pragma once

#include <iostream>
#include <SDL.h>
#include "GameObject.h"
#include "Grid.h"
#include "Game.h"

typedef enum TextureLabel
{
	Case2 = 0,
	Case4 = 1,
	Case8 = 2,
	Case16 = 3,
	Case32 = 4,
	Case64 = 5,
	Case128 = 6,
	Case256 = 7,
	Case512 = 8,
	Case1024 = 9,
	Case2048 = 10,
};

class Window
{
	/* Classe qui va g�rer tout le rendu visuel*/
private:
	int screenWidth;
	int screenHeight;
	int nbColonnes;
	int nbLignes;
	int tileSizeX;
	int tileSizeY;
	int interTileoffset;
	int borderOffset;
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	Window(int screenWidth, int screenHeight, int nbColonnes, int nbLignes, int tileSizeX, int tileSizeY, int interTileoffset, int borderOffset); // constructor

	void initSDL(); // m�thode pour initialiser SDL
	void initGrid();// m�thode pour initialiser l'affichage de la grille 
	void renderImage(int number, int x, int y, int h, int w, SDL_Texture** imageTexture); // m�thode pour afficher nos chiffres
	void graphicDisplay(Grid* o_grid, SDL_Texture** imageTexture); // m�thode pour afficher la grille de jeu
	SDL_Renderer* getRenderer(); // m�thode pour r�cup�rer un renderer
	SDL_Window* getWindow(); // m�thode pour r�cup�rer une window
	void cleanUpSDL(); // m�thode pour d�truire SDL
};

