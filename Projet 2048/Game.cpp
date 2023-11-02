#include "Game.h"
#include <string>
#include <conio.h>


Game::Game(int x, int y)
{
	this->sizeX = x;
	this->sizeY = y;
	this->isLoad = false;
};

void Game::initImageTile(SDL_Renderer* renderer)
{

	int value = 2;

	for (int i = 0; i < 11; i++)
	{
		GameObject* o_gameObject = new GameObject(value);
		o_gameObject->setPath();

		SDL_Surface* image = SDL_LoadBMP(o_gameObject->getPath().c_str()); // envoie d'un string qui est ensuite modifier en char* avec la fonction c_str()
		SDL_Texture* myImage = SDL_CreateTextureFromSurface(renderer, image);  //La texture monImage contient maintenant l'image importée

		SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface


		this->imageTextures[i] = myImage;

		delete o_gameObject;

		value += value;
	}
}

void Game::initImageTexture(SDL_Renderer* renderer)
{
	if (!this->isLoad)
	{
		this->initImageTile(renderer);

		SDL_Surface* win = SDL_LoadBMP("Image/win.bmp");
		SDL_Surface* lose = SDL_LoadBMP("Image/lose.bmp");
		SDL_Surface* start = SDL_LoadBMP("Image/Start.bmp");
		SDL_Surface* quit = SDL_LoadBMP("Image/Quit.bmp");
		SDL_Surface* retry = SDL_LoadBMP("Image/Retry.bmp");

		SDL_Texture* winImage = SDL_CreateTextureFromSurface(renderer, win);
		SDL_Texture* loseImage = SDL_CreateTextureFromSurface(renderer, lose);
		SDL_Texture* startImage = SDL_CreateTextureFromSurface(renderer, start);
		SDL_Texture* quitImage = SDL_CreateTextureFromSurface(renderer, quit);
		SDL_Texture* retryImage = SDL_CreateTextureFromSurface(renderer, retry);

		SDL_FreeSurface(win); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
		SDL_FreeSurface(lose); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
		SDL_FreeSurface(start); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
		SDL_FreeSurface(quit); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
		SDL_FreeSurface(retry); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

		this->imageActions[0] = startImage;
		this->imageActions[1] = retryImage;
		this->imageActions[2] = quitImage;
		this->imageActions[3] = winImage;
		this->imageActions[4] = loseImage;

		this->isLoad = true;
	}
}

void Game::destroyTextures()
{
	for (int i = 0; i < 11; i++)
	{
		SDL_DestroyTexture(this->imageTextures[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		SDL_DestroyTexture(this->imageActions[i]);
	}
}

SDL_Texture** Game::getTileTexture()
{
	return this->imageTextures;
}

void Game::endGameDisplay(int number, int screenWidth, int screenHeight, SDL_Renderer* renderer)
{
	SDL_Rect winAndLose;
	winAndLose.x = (screenWidth - 1200) / 2;
	winAndLose.y = ((screenHeight - 600) / 2) - 30;
	winAndLose.h = 600;
	winAndLose.w = 1200;

	SDL_Rect actions;
	actions.x = (winAndLose.x + (winAndLose.w - (3*200) - (2*50)))/2;
	actions.y = winAndLose.y + winAndLose.h + 20;
	actions.h = 100;
	actions.w = 200;

	if (number == 1)
	{
		SDL_RenderCopy(renderer, this->imageActions[win], NULL, &winAndLose);
	}
	else
	{
		SDL_RenderCopy(renderer, this->imageActions[lose], NULL, &winAndLose);
	}
	SDL_RenderCopy(renderer, this->imageActions[start], NULL, &actions);

	actions.x += 250;

	SDL_RenderCopy(renderer, this->imageActions[restart], NULL, &actions);

	actions.x += 250;

	SDL_RenderCopy(renderer, this->imageActions[quit], NULL, &actions);

	SDL_RenderPresent(renderer);
}


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

	Grid* o_grid = new Grid(this->sizeX, this->sizeY);
	Window* o_window = new Window(screenWidth, screenHeight, this->sizeX, this->sizeY, 150, 150, 25, 15);

	this->initImageTexture(o_window->getRenderer());

	o_grid->tileSetRandomNumber(2);
	o_window->graphicDisplay(o_grid, this->getTileTexture());

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

	//	//DRAW
		o_window->graphicDisplay(o_grid, this->getTileTexture());

	//	//UPDATE

		/* Vérification de win et lose */
		if (o_grid->conditionGameWin())
		{
			this->endGameDisplay(1, screenWidth,screenHeight, o_window->getRenderer());

			delete o_grid;
			delete o_window;

			this->restartGame();

			return;
		}
		else if (o_grid->conditionGameLose())
		{
			this->endGameDisplay(0, screenWidth, screenHeight, o_window->getRenderer());

			delete o_grid;
			delete o_window;

			this->restartGame();

			return;
		}
	}
	o_window->cleanUpSDL();
	this->destroyTextures();
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