#include "Game.h"
#include <string>
#include <conio.h>


Game::Game(int x, int y, int screenWidth, int screenHeight)
{
	/* Constructor */
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
	/* Méthode pour initialiser toutes les textures des tiles */
	int value = 2;

	for (int i = 0; i < 11; i++)
	{
		GameObject* o_gameObject = new GameObject(value);
		o_gameObject->setPath();

		SDL_Surface* image = SDL_LoadBMP(o_gameObject->getPath().c_str()); // envoie d'un string qui est ensuite modifier en char* avec la fonction c_str()
		SDL_Texture* myImage = SDL_CreateTextureFromSurface(renderer, image);  //La texture monImage contient maintenant l'image importée

		SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface


		this->imageTextures[i] = myImage; // définition de imageTextures d'id I avec notre texture

		delete o_gameObject; // libérer l'adresse mémoire

		value += value;
	}
}

void Game::initImageTexture(SDL_Renderer* renderer)
{
	/* Méthode pour initialiser toutes les textures */
	if (!this->isLoad) // vérifie sur on a déjà load les textures
	{
		this->initImageTile(renderer);

		/* Initialisation des surfaces */
		SDL_Surface* win = SDL_LoadBMP("Image/win.bmp");
		SDL_Surface* lose = SDL_LoadBMP("Image/lose.bmp");
		SDL_Surface* start = SDL_LoadBMP("Image/Start.bmp");
		SDL_Surface* quit = SDL_LoadBMP("Image/Quit.bmp");
		SDL_Surface* retry = SDL_LoadBMP("Image/Retry.bmp");
		SDL_Surface* startScreen = SDL_LoadBMP("Image/StartScreen.bmp");

		/* Initialisation des textures */
		SDL_Texture* winImage = SDL_CreateTextureFromSurface(renderer, win);
		SDL_Texture* loseImage = SDL_CreateTextureFromSurface(renderer, lose);
		SDL_Texture* startImage = SDL_CreateTextureFromSurface(renderer, start);
		SDL_Texture* quitImage = SDL_CreateTextureFromSurface(renderer, quit);
		SDL_Texture* retryImage = SDL_CreateTextureFromSurface(renderer, retry);
		SDL_Texture* startScreenImage = SDL_CreateTextureFromSurface(renderer, startScreen);

		/* Libération de la mémoire des surface */
		SDL_FreeSurface(win); 
		SDL_FreeSurface(lose);
		SDL_FreeSurface(start);
		SDL_FreeSurface(quit);
		SDL_FreeSurface(retry); 
		SDL_FreeSurface(startScreen);

		/* Instantiation des textures avec nos différents tableaux*/
		this->imageActions[0] = startImage;
		this->imageActions[1] = retryImage;
		this->imageActions[2] = quitImage;
		this->imageActions[3] = winImage;
		this->imageActions[4] = loseImage;

		this->imageStartScreen[0] = startScreenImage;

		this->isLoad = true; // défini que l'on a déjà charger les textures
	}
}

void Game::destroyTextures()
{
	/* Méthode pour détruire toutes les textures */
	for (int i = 0; i < 11; i++)
	{
		SDL_DestroyTexture(this->imageTextures[i]); // destruction de la texture
	}

	for (int i = 0; i < 5; i++)
	{
		SDL_DestroyTexture(this->imageActions[i]); // destruction de la texture
	}
	SDL_DestroyTexture(this->imageStartScreen[0]); // destruction de la texture
}

SDL_Texture** Game::getTileTexture()
{
	/* Méthode pour récupérer le tableau des textures */
	return this->imageTextures;
}

void Game::startGameDisplay(SDL_Renderer* renderer)
{
	/* Méthode pour l'affichage du début de partie*/
	SDL_Rect startScreen;// box dans laquelle sera afficher notre menu
	startScreen.x = 0;
	startScreen.y = 0;
	startScreen.h = this->screenHeight;
	startScreen.w = this->screenWidth;

	SDL_Rect action;// box dans lesquelles sera affiché nos options
	action.x = this->actionsX + 60;
	action.y = 325;
	action.h = this->actionsH;
	action.w = this->actionsW;

	SDL_RenderCopy(renderer, this->imageStartScreen[0], NULL, &startScreen); // modifie les pixels de notre canva

	SDL_RenderCopy(renderer, this->imageActions[start], NULL, &action);

	action.x += this->actionsW + this->gapBetweenActions; // ajout d'une distance entre les options in game

	SDL_RenderCopy(renderer, this->imageActions[quit], NULL, &action);

	SDL_RenderPresent(renderer); // affichage des modifications
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
			this->restartGame(); // relancer le jeu
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
	bool isGameOver = false;

	SDL_Event event;

	Grid* o_grid = new Grid(this->sizeX, this->sizeY);
	Window* o_window = new Window(this->screenWidth, this->screenHeight, this->sizeX, this->sizeY, 150, 150, 25, 15);

	this->initImageTexture(o_window->getRenderer());

	if (!this->isStarted) // vérifie si la partie à commencée
	{
		this->startGameDisplay(o_window->getRenderer());
		isGameOver = true;
	}
	
	while (1) {
		/* EVENT */
		if (!isGameOver) // vérifie si la partie est terminée
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
						/* Menu de départ */
						if (!this->isStarted && event.button.x >= (this->actionsX + 60) && event.button.x <= ((this->actionsX + 60) + this->actionsW) && event.button.y >= 325 && event.button.y <= (325 + this->actionsH))
						{
							// condition pour vérifier si la souris de l'utilisateur se trouve sur le bouton start du menu d'accueil
							this->isStarted = true;
							isGameOver = false;
							o_window->initGrid(); // affichage de la grille
							o_grid->tileSetRandomNumber(2); // initialisation des chiffres random dans la grille
							o_window->graphicDisplay(o_grid, this->getTileTexture()); // affichage version graphique du jeu

						}
						else if (!this->isStarted && event.button.x >= ((this->actionsX + 60) + this->actionsW + this->gapBetweenActions) && event.button.x <= ((this->actionsX + 60) + this->actionsW + (this->actionsW + this->gapBetweenActions)) && event.button.y >= 325 && event.button.y <= (325 + this->actionsH))
						{
							// condition pour vérifier si la souris de l'utilisateur se trouve sur le bouton quit du menu d'accueil
							this->isStarted = true;
							o_window->cleanUpSDL();
							this->destroyTextures(); //destruction des textures
							delete o_window;
							delete o_grid;
							return;

						}
						/* Menu de fin */
						else if (this->isStarted && event.button.x >= this->actionsX && event.button.x <= (this->actionsX + this->actionsW) && event.button.y >= this->actionsY && event.button.y <= (this->actionsY + this->actionsH))
						{
							// condition pour vérifier si la souris de l'utilisateur se trouve sur le bouton restart

							this->startGameGraphic();
						}
						else if (this->isStarted && event.button.x >= (this->actionsX + this->actionsW + this->gapBetweenActions) && event.button.x <= (this->actionsX + this->actionsW + (this->actionsW + this->gapBetweenActions)) && event.button.y >= this->actionsY && event.button.y <= (this->actionsY + this->actionsH))
						{
							// condition pour vérifier si la souris de l'utilisateur se trouve sur le bouton quit

							o_window->cleanUpSDL();
							this->destroyTextures();
							delete o_window; 
							delete o_grid;
							return;
						}
					}
				}
			}
		}

		//DRAW
		o_window->graphicDisplay(o_grid, this->getTileTexture());

		//UPDATE

		/* Vérification de win et lose */
		if (o_grid->conditionGameWin())
		{
			this->endGameDisplay(1, o_window->getRenderer()); // affichage menu de win
			isGameOver = true;
		}
		else if (o_grid->conditionGameLose())
		{
			this->endGameDisplay(0, o_window->getRenderer()); // affichage menu de lose
			isGameOver = true;
		}
	}
}

void Game::restartGame()
{
	/* Méthode pour relancer le jeu */
	std::string response = "";
	std::string isGraphic = "";
	while (response != "y" && response != "Y" && response != "n" && response !="N")
	{
		std::cout << "Voulez vous rejouer ? (y or n)" << std::endl; // demande à l'utilisateur via la console
		std::cin >> response;
	}

	if (response == "y" || response == "Y")
	{
		// y pour yes
		while (response != "y" && response != "Y" && response != "n" && response != "N")
		{
			std::cout << "Voulez vous que cette nouvelle partie soit en version graphique ? (y or n)" << std::endl; // demande à l'utilisateur via la console
			std::cin >> isGraphic;
		}
		if (isGraphic == "y" || isGraphic == "Y")
		{
			this->startGameGraphic(); // relance le jeu en graphique
		}
		else
		{
			this->startGame(); // relance le jeu en console
		}
	}
};

void Game::endGameDisplay(int number, SDL_Renderer* renderer)
{
	/* Méthode pour l'affichage d'une fin de partie*/
	SDL_Rect winAndLose; // box dans laquelle sera afficher notre menu
	winAndLose.x = this->winAndLoseX;
	winAndLose.y = this->winAndLoseY;
	winAndLose.h = this->winAndLoseH;
	winAndLose.w = this->winAndLoseW;

	SDL_Rect actions;// box dans lesquelles sera affiché nos options
	actions.x = this->actionsX;
	actions.y = this->actionsY;
	actions.h = this->actionsH;
	actions.w = this->actionsW;

	if (number == 1) // cas de victoire
	{
		SDL_RenderCopy(renderer, this->imageActions[win], NULL, &winAndLose); // modifie les pixels de notre canva
	}
	else // cas de défaite
	{
		SDL_RenderCopy(renderer, this->imageActions[lose], NULL, &winAndLose);
	}

	SDL_RenderCopy(renderer, this->imageActions[restart], NULL, &actions);

	actions.x += this->actionsW + this->gapBetweenActions; // ajout d'une distance entre les options in game

	SDL_RenderCopy(renderer, this->imageActions[quit], NULL, &actions);

	SDL_RenderPresent(renderer); // affichage des modifications
}
