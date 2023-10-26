#include <iostream>
#include "Grid.h"
#include "Tile.h"
#include <Windows.h>
#include <vector>


int main()
{
    srand(time(NULL));

    Grid* o_grid = new Grid(4, 4);
    o_grid->searchGridPlace();
    //o_grid->display();
    o_grid->tileSetRandomNumber(2);
    o_grid->changeValueWithCoordinates(0, 0, 2048);
    o_grid->conditionGameWin();


    /*while (1) {
        std::vector<int> movement = o_grid->movement();
        o_grid->moveTile(2,3, movement);
    }*/

    delete o_grid;
}

