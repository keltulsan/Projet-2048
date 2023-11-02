#include "Game.h"
#include <string>
#include <conio.h>


Game::Game(int x, int y)
{
	this->sizeX = x;
	this->sizeY = y;
};


void Game::startGame()
{
	/* Méthode pour lancer le jeu*/
	Grid* o_grid = new Grid(this->sizeX, this->sizeY);

	o_grid->tileSetRandomNumber(2);


	while (1) {

		/* Vérification de win et lose */
		if (o_grid->conditionGameWin())
		{
			std::cout << "YOU WIN" << std::endl;
			delete o_grid;
			this->restartGame();
			return;
		}
		else if (o_grid->conditionGameLose())
		{
			std::cout << "YOU Lose" << std::endl;
			delete o_grid;
			this->restartGame();
			return;
		}

		/* Controllers */
		int keyValue = _getch();

		if (KEY_UP == keyValue || KEY_Z == keyValue) {
			// key up
			o_grid->playUp();
		}

		else if (KEY_DOWN == keyValue || KEY_S == keyValue) {
			// key down
			o_grid->playDown();
		}

		else if (KEY_LEFT == keyValue || KEY_Q == keyValue) {
			// key left
			o_grid->playLeft();
		}

		else if (KEY_RIGHT == keyValue || KEY_D == keyValue) {
			// key right
			o_grid->playRight();
		}

	}
}

void Game::startGameGraphic()
{
	/* Méthode pour lancer le jeu version graphique */
	SDL_Event event;

	int screenWidth = 1280;
	int screenHeight = 800;

	SDL_Rect rect;/*
	rect.x = (screenWidth - 800) / 2;
	rect.y = (screenHeight - 400) / 2;*/
	rect.x = 0;
	rect.y = 0;
	rect.h = 800;
	rect.w = 400;

	Grid* o_grid = new Grid(this->sizeX, this->sizeY);
	Window* o_window = new Window(screenWidth, screenHeight, this->sizeX, this->sizeY, 150, 150, 25, 15);

	o_window->init();

	o_grid->tileSetRandomNumber(2);
	o_window->graphicDisplay(o_grid);

	while (1) {
		//EVENT
		int keyValue = 0;// _getch();
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_z) {
					// key up
					o_grid->playUp();
				}

				else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) {
					// key down
					o_grid->playDown();
				}

				else if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_q) {
					// key left
					o_grid->playLeft();
				}

				else if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d) {
					// key right
					o_grid->playRight();
				}
			}
		}

		//DRAW
		o_window->graphicDisplay(o_grid);

		//UPDATE

		/* Vérification de win et lose */
		if (o_grid->conditionGameWin())
		{
			SDL_Surface* image = SDL_LoadBMP("Image/win.bmp");
			SDL_Texture* myImage = SDL_CreateTextureFromSurface(o_window->getRenderer(), image);

			SDL_RenderCopy(o_window->getRenderer(), myImage, NULL, &rect);
			SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

			o_window->cleanUpSDL();

			delete o_grid;
			delete o_window;

			this->restartGame();

			return;
		}
		else if (o_grid->conditionGameLose())
		{
			SDL_Surface* image = SDL_LoadBMP("Image/lose.bmp");
			SDL_Texture* myImage = SDL_CreateTextureFromSurface(o_window->getRenderer(), image);

			if (myImage == NULL)
			{
				std::cout << "null";
			}

			SDL_RenderCopy(o_window->getRenderer(), myImage, NULL, &rect);
			SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

			//o_window->cleanUpSDL();

			delete o_grid;
			delete o_window;

			this->restartGame();

			return;
		}

	}
}

void Game::restartGame()
{
	/* Méthode pour relancer le jeu */
	std::string response = "";
	std::string isGraphic = "";
	std::cout << "Voulez vous rejouer ? (y or n)" << std::endl; // demande à l'utilisateur via la console
	std::cin >> response;
	if (response == "y")
	{
		// y pour yes
		std::cout << "Voulez vous que cette nouvelle partie soit en version graphique ? (y or n)" << std::endl; // demande à l'utilisateur via la console
		std::cin >> isGraphic;
		if (isGraphic == "y")
		{
			this->startGameGraphic();
		}
		else
		{
			this->startGame();
		}
	}
};