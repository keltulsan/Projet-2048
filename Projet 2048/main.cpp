#include <iostream>
#include "Grid.h"
#include "Tile.h"
#include "Test.h"
#include <Windows.h>
#include <vector>


void IntegrationTest() 
{
    Test o_test;

    o_test.moveRight();
    o_test.moveLeft();
    o_test.moveUp();
    o_test.moveDown();
    o_test.moveRightSide();
    o_test.moveLeftSide();
    o_test.moveUpSide();
    o_test.moveDownSide();
    o_test.fusionRight();
    o_test.fusionLeft();
    o_test.fusionUp();
    o_test.fusionDown();
    o_test.fusionUpSide();
    o_test.fusionDownSide();
    o_test.fusionLeftSide();
    o_test.fusionRightSide();
    o_test.up();
    o_test.down();
    o_test.left();
    o_test.right();
}

void IntegrationGame()
{
    srand(time(NULL));

    Grid* o_grid = new Grid(4, 4);

      o_grid->game();
//    o_grid->searchGridPlace();
//
//    //o_grid->changeValueWithCoordinates(0, 0, 4);
//    //o_grid->changeValueWithCoordinates(1, 0, 4);
//    //o_grid->changeValueWithCoordinates(2, 0, 2);
//    o_grid->changeValueWithCoordinates(3, 0, 2);
//
//    //o_grid->changeValueWithCoordinates(0, 1, 4);
//    //o_grid->changeValueWithCoordinates(1, 1, 2);
//    //o_grid->changeValueWithCoordinates(2, 1, 2);
//    //o_grid->changeValueWithCoordinates(3, 1, 4);
//


    delete o_grid;
}

int main()
{
    IntegrationTest();
    //IntegrationGame();

    return 0;
}

