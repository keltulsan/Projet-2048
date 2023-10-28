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
	Grid* o_grid = new Grid(this->sizeX, this->sizeY);

	o_grid->tileSetRandomNumber(2);


	while (1) {

		/* Vérification de win et lose */
		if (o_grid->conditionGameWin())
		{
			std::cout << "YOU WIN" << std::endl;
			return;
		}
		else if (o_grid->conditionGameLose())
		{
			std::cout << "YOU Lose" << std::endl;
			return;
		}

		/* Controllers */
		int keyValue = _getch();

		if (KEY_UP == keyValue || KEY_Z == keyValue) {
			//key up
			o_grid->up();
			o_grid->tileSetRandomNumber(1);
		}

		else if (KEY_DOWN == keyValue || KEY_S == keyValue) {
			// key down
			o_grid->down();
			o_grid->tileSetRandomNumber(1);
		}

		else if (KEY_LEFT == keyValue || KEY_Q == keyValue) {
			// key left
			o_grid->left();
			o_grid->tileSetRandomNumber(1);
		}

		else if (KEY_RIGHT == keyValue || KEY_D == keyValue) {
			// key right
			o_grid->right();
			o_grid->tileSetRandomNumber(1);
		}

	}
}
void Game::restartGame()
{
	std::string response = "";
	std::cout << "Voulez vous rejouer ? (y or n)" << std::endl;
	std::cin >> response;
	if (response == "y")
	{
		this->startGame();
	}
};