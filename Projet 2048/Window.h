#pragma once

#include <iostream>
#include <SDL.h>
#include "GameObject.h"
#include "Grid.h"

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
	SDL_Texture* imageTextures[11];
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Surface* surface;

public:
	Window(int screenWidth, int screenHeight, int nbColonnes, int nbLignes, int tileSizeX, int tileSizeY, int interTileoffset, int borderOffset);

	void init();
	void initSDL();
	void cleanUpSDL();
	void renderImage(int number, int x, int y, int h, int w);
	void initGrid();
	void graphicDisplay(Grid* o_grid);
	void initImageTexture();
	SDL_Renderer* getRenderer();
};

