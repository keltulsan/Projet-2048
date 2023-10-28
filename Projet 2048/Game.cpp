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
void Game::restartGame()
{
	/* Méthode pour relancer le jeu */
	std::string response = "";
	std::cout << "Voulez vous rejouer ? (y or n)" << std::endl; // demande à l'utilisateur via la console
	std::cin >> response;
	if (response == "y")
	{
		// y pour yes
		this->startGame();
	}
};