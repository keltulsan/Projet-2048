#include <iostream>
#include "Grid.h"

int main()
{
    Grid* o_grid = new Grid(5, 5);

    o_grid->display();
    o_grid->changeValueWithCoordinates(5, 5, 9);

    delete o_grid;
}

