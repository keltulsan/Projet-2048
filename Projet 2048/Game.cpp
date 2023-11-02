#include "Game.h"
#include <string>
#include <conio.h>


Game::Game(int x, int y, int screenWidth, int screenHeight)
{
	this->sizeX = x;
	this->sizeY = y;
	this->isLoad = false;
	this->isStarted = false;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->winAndLoseX = (this->screenWidth - 1200) / 2;
	this->winAndLoseY = ((this->screenHeight - 600) / 2) - 30;
	this->winAndLoseW = 1200;
	this->winAndLoseH = 600;

	this->actionsX = (this->winAndLoseW - (2 * 200) - (1 * 50)) / 2;
	this->actionsY = this->winAndLoseY + this->winAndLoseH + 20;
	this->actionsW = 200;
	this->actionsH = 100;

	this->gapBetweenActions = 50;

};

void Game::initImageTile(SDL_Renderer* renderer)
{

	int value = 2;

	for (int i = 0; i < 11; i++)
	{
		GameObject* o_gameObject = new GameObject(value);
		o_gameObject->setPath();

		SDL_Surface* image = SDL_LoadBMP(o_gameObject->getPath().c_str()); // envoie d'un string qui est ensuite modifier en char* avec la fonction c_str()
		SDL_Texture* myImage = SDL_CreateTextureFromSurface(renderer, image);  //La texture monImage contient maintenant l'image import�e

		SDL_FreeSurface(image); //�quivalent du destroyTexture pour les surface, permet de lib�rer la m�moire quand on n'a plus besoin d'une surface


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
		SDL_Surface* startScreen = SDL_LoadBMP("Image/StartScreen.bmp");

		SDL_Texture* winImage = SDL_CreateTextureFromSurface(renderer, win);
		SDL_Texture* loseImage = SDL_CreateTextureFromSurface(renderer, lose);
		SDL_Texture* startImage = SDL_CreateTextureFromSurface(renderer, start);
		SDL_Texture* quitImage = SDL_CreateTextureFromSurface(renderer, quit);
		SDL_Texture* retryImage = SDL_CreateTextureFromSurface(renderer, retry);
		SDL_Texture* startScreenImage = SDL_CreateTextureFromSurface(renderer, startScreen);

		SDL_FreeSurface(win); //�quivalent du destroyTexture pour les surface, permet de lib�rer la m�moire quand on n'a plus besoin d'une surface
		SDL_FreeSurface(lose); //�quivalent du destroyTexture pour les surface, permet de lib�rer la m�moire quand on n'a plus besoin d'une surface
		SDL_FreeSurface(start); //�quivalent du destroyTexture pour les surface, permet de lib�rer la m�moire quand on n'a plus besoin d'une surface
		SDL_FreeSurface(quit); //�quivalent du destroyTexture pour les surface, permet de lib�rer la m�moire quand on n'a plus besoin d'une surface
		SDL_FreeSurface(retry); //�quivalent du destroyTexture pour les surface, permet de lib�rer la m�moire quand on n'a plus besoin d'une surface
		SDL_FreeSurface(startScreen); //�quivalent du destroyTexture pour les surface, permet de lib�rer la m�moire quand on n'a plus besoin d'une surface

		this->imageActions[0] = startImage;
		this->imageActions[1] = retryImage;
		this->imageActions[2] = quitImage;
		this->imageActions[3] = winImage;
		this->imageActions[4] = loseImage;

		this->imageStartScreen[0] = startScreenImage;

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

void Game::endGameDisplay(int number, SDL_Renderer* renderer)
{
	SDL_Rect winAndLose;
	winAndLose.x = this->winAndLoseX;
	winAndLose.y = this->winAndLoseY;
	winAndLose.h = this->winAndLoseH;
	winAndLose.w = this->winAndLoseW;

	SDL_Rect actions;
	actions.x = this->actionsX;
	actions.y = this->actionsY;
	actions.h = this->actionsH;
	actions.w = this->actionsW;

	if (number == 1)
	{
		SDL_RenderCopy(renderer, this->imageActions[win], NULL, &winAndLose);
	}
	else
	{
		SDL_RenderCopy(renderer, this->imageActions[lose], NULL, &winAndLose);
	}

	SDL_RenderCopy(renderer, this->imageActions[restart], NULL, &actions);

	actions.x += this->actionsW + this->gapBetweenActions;

	SDL_RenderCopy(renderer, this->imageActions[quit], NULL, &actions);

	SDL_RenderPresent(renderer);
}


void Game::startGameDisplay(SDL_Renderer* renderer)
{
	SDL_Rect startScreen;
	startScreen.x = 0;
	startScreen.y = 0;
	startScreen.h = this->screenHeight;
	startScreen.w = this->screenWidth;

	SDL_Rect action;
	action.x = this->actionsX + 60;
	action.y = 325;
	action.h = this->actionsH;
	action.w = this->actionsW;

	SDL_RenderCopy(renderer, this->imageStartScreen[0], NULL, &startScreen);

	SDL_RenderCopy(renderer, this->imageActions[start], NULL, &action);
	action.x += this->actionsW + this->gapBetweenActions;
	SDL_RenderCopy(renderer, this->imageActions[quit], NULL, &action);

	SDL_RenderPresent(renderer);

}

void Game::startGame()
{
	/* M�thode pour lancer le jeu*/
	Grid* o_grid = new Grid(this->sizeX, this->sizeY);

	o_grid->tileSetRandomNumber(2);


	while (1) {

		/* V�rification de win et lose */
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
	/* M�thode pour lancer le jeu version graphique */
	bool isGameOver = false;

	SDL_Event event;

	Grid* o_grid = new Grid(this->sizeX, this->sizeY);
	Window* o_window = new Window(this->screenWidth, this->screenHeight, this->sizeX, this->sizeY, 150, 150, 25, 15);

	this->initImageTexture(o_window->getRenderer());

	if (!this->isStarted)
	{
		this->startGameDisplay(o_window->getRenderer());
		isGameOver = true;
	}
	


	while (1) {
		//EVENT
		if (!isGameOver)
		{
			while (SDL_PollEvent(&event) && isGameOver == false)
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
		}
		else if (isGameOver)
		{
			while (SDL_WaitEvent(&event) && isGameOver)
			{
		
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						
						if (!this->isStarted && event.button.x >= (this->actionsX + 60) && event.button.x <= ((this->actionsX + 60) + this->actionsW) && event.button.y >= 325 && event.button.y <= (325 + this->actionsH))
						{
							// condition pour v�rifier si la souris de l'utilisateur se trouve sur le bouton start du menu d'accueil
							this->isStarted = true;
							isGameOver = false;
							o_window->initGrid();
							o_grid->tileSetRandomNumber(2);
							o_window->graphicDisplay(o_grid, this->getTileTexture());

						}
						else if (!this->isStarted && event.button.x >= ((this->actionsX + 60) + this->actionsW + this->gapBetweenActions) && event.button.x <= ((this->actionsX + 60) + this->actionsW + (this->actionsW + this->gapBetweenActions)) && event.button.y >= 325 && event.button.y <= (325 + this->actionsH))
						{
							// condition pour v�rifier si la souris de l'utilisateur se trouve sur le bouton quit du menu d'accueil
							this->isStarted = true;
							o_window->cleanUpSDL();
							this->destroyTextures();
							return;

						}
						else if (this->isStarted && event.button.x >= this->actionsX && event.button.x <= (this->actionsX + this->actionsW) && event.button.y >= this->actionsY && event.button.y <= (this->actionsY + this->actionsH))
						{
							// condition pour v�rifier si la souris de l'utilisateur se trouve sur le bouton restart

							this->startGameGraphic();
						}
						else if (this->isStarted && event.button.x >= (this->actionsX + this->actionsW + this->gapBetweenActions) && event.button.x <= (this->actionsX + this->actionsW + (this->actionsW + this->gapBetweenActions)) && event.button.y >= this->actionsY && event.button.y <= (this->actionsY + this->actionsH))
						{
							// condition pour v�rifier si la souris de l'utilisateur se trouve sur le bouton quit

							o_window->cleanUpSDL();
							this->destroyTextures();
							return;
						}
					}
				}
			}
		}

	//	//DRAW
		o_window->graphicDisplay(o_grid, this->getTileTexture());

	//	//UPDATE

		/* V�rification de win et lose */
		if (o_grid->conditionGameWin())
		{
			this->endGameDisplay(1, o_window->getRenderer());
			isGameOver = true;

			delete o_grid;
			delete o_window;
		}
		else if (o_grid->conditionGameLose())
		{
			this->endGameDisplay(0, o_window->getRenderer());
			isGameOver = true;

			delete o_grid;
			delete o_window;
		}
	}
}

void Game::restartGame()
{
	/* M�thode pour relancer le jeu */
	std::string response = "";
	std::string isGraphic = "";
	std::cout << "Voulez vous rejouer ? (y or n)" << std::endl; // demande � l'utilisateur via la console
	std::cin >> response;
	if (response == "y" || response == "Y")
	{
		// y pour yes
		std::cout << "Voulez vous que cette nouvelle partie soit en version graphique ? (y or n)" << std::endl; // demande � l'utilisateur via la console
		std::cin >> isGraphic;
		if (isGraphic == "y" || isGraphic == "Y")
		{
			this->startGameGraphic();
		}
		else
		{
			this->startGame();
		}
	}
};
