#pragma once

#include <iostream>
#include <SDL.h>
#include "GameObject.h"
#include "Grid.h"

class Window 
{
	/* Classe qui va gérer tout le rendu visuel*/
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
	SDL_Texture* texture;
	SDL_Surface* surface;

public: 
	Window(int screenWidth, int screenHeight, int nbColonnes, int nbLignes, int tileSizeX, int tileSizeY, int interTileoffset, int borderOffset);

	void initSDL();
	void cleanUpSDL();
	void renderImage(int number, int x, int y, int h, int w);
	void initGrid();
	void graphicDisplay(Grid* o_grid);
};

