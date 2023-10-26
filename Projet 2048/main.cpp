#include <iostream>
#include "Grid.h"
#include "Tile.h"
#include <Windows.h>
#include <vector>


int main()
{
    srand(time(NULL));

    Grid* o_grid = new Grid(4, 4);
    //o_grid->game();
    o_grid->changeValueWithCoordinates(0, 0, 2);
    o_grid->changeValueWithCoordinates(1, 0, 2);
    o_grid->changeValueWithCoordinates(2, 0, 4);
    o_grid->changeValueWithCoordinates(1, 2, 2);
    while (1) {
        std::vector<int> dist = o_grid->controllers();
        o_grid->moveTile(2, 0, dist);
    }
    delete o_grid;
}

