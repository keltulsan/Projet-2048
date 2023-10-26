#include <iostream>
#include "Grid.h"
#include "Tile.h"
#include <Windows.h>
#include <vector>


int main()
{
    srand(time(NULL));

    Grid* o_grid = new Grid(4, 4);
    //o_grid->display();
    o_grid->tileSetRandomNumber(2);
    //std::cout << o_grid->getIdByCoordinates(0, 0);


    /*while (1) {
        std::vector<int> movement = o_grid->movement();
        o_grid->moveTile(2,3, movement);
    }*/

    delete o_grid;
}

