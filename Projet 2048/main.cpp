#include <iostream>
#include "Grid.h"
#include "Tile.h"
#include "Test.h"
#include <Windows.h>
#include <vector>


void IntegrationTest() 
{
    Test o_test;

    o_test.moveUp();
}

void IntegrationGame()
{
    srand(time(NULL));

    Grid* o_grid = new Grid(4, 4);

    //o_grid->game();
    o_grid->searchGridPlace();

    //o_grid->changeValueWithCoordinates(0, 0, 4);
    //o_grid->changeValueWithCoordinates(1, 0, 4);
    //o_grid->changeValueWithCoordinates(2, 0, 2);
    o_grid->changeValueWithCoordinates(3, 0, 2);

    //o_grid->changeValueWithCoordinates(0, 1, 4);
    //o_grid->changeValueWithCoordinates(1, 1, 2);
    //o_grid->changeValueWithCoordinates(2, 1, 2);
    //o_grid->changeValueWithCoordinates(3, 1, 4);

    o_grid->display();
    while (1) {
       std::vector<int> dist = o_grid->controllers();
       //o_grid->moveTile(dist);
        o_grid->movement(0, 0, dist[0], dist[1]);

    }

    delete o_grid;
}

int main()
{
    //IntegrationTest();
    IntegrationGame();

    return 0;
}

