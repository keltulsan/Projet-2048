#include "Game.h"

Game::Game()
{
	Grid o_Grid = Grid(4, 4);
	o_Grid.searchGridPlace();
	o_Grid.tileSetRandomNumber(2);
	while (1) {
		o_Grid.controllers();
	}
}