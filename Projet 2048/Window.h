#pragma once

#include <iostream>
#include <SDL.h>
#include "GameObject.h"

class Window 
{
	/* Classe qui va gérer tout le rendu visuel*/
private:
	int screenWidth;
	int screenHeight;
	int nbColonnes;
	int nbLignes;
	int TileSixeX;
	int TileSixeY;
	SDL_Window* window;
	SDL_Renderer* renderer;

public: 
	Window(int nbColonnes, int nbLignes, int TileSixeX, int TileSixeY, int screenWidth, int screenHeight);

	void initSDL();
	void cleanUpSDL();
	void startGraphicRender();
	void gridDisplay();
};

