#include <iostream>
#include "Grid.h"
#include "Tile.h"
#include <Windows.h>


int main()
{
    Grid* o_grid = new Grid(4, 4);
    o_grid->display();
    o_grid->changeValueWithCoordinates(2, 2, 9);


    while (1) {
        int movement = o_grid->movement();
        o_grid->moveTile(2, 2, movement);
    }

    delete o_grid;

}

