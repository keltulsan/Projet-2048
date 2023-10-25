#include <iostream>
#include "Grid.h"
#include "Tile.h"
#include <Windows.h>
#include <vector>


int main()
{
    Grid* o_grid = new Grid(4, 4);
    o_grid->display();
    o_grid->changeValueWithCoordinates(0, 3, 8);
    o_grid->changeValueWithCoordinates(2, 3, 8);


    while (1) {
        std::vector<int> movement = o_grid->movement();
        o_grid->moveTile(2,3, movement);
    }

    delete o_grid;
}

