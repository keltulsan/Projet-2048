#include <iostream>
#include "Grid.h"
#include "Tile.h"
#include <Windows.h>


int main()
{
    Grid* o_grid = new Grid(4, 4);
    o_grid->display();
    o_grid->changeValueWithCoordinates(3, 3, 9);
    //o_grid->changeValueWithCoordinates(2, 4, 8);


    while (1) {
        int movement = o_grid->movement();
        o_grid->moveTile(3,3, movement);
    }

    delete o_grid;

}

