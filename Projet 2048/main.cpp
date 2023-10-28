#include <iostream>
#include "Grid.h"
#include "Tile.h"
#include "Game.h"
#include "Test.h"
#include <Windows.h>
#include <vector>


void IntegrationTest() 
{
    Test o_test;
    o_test.gridCreateCopy();
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
    o_test.win();
    o_test.lose();
}

void IntegrationGame()
{
    srand(time(NULL));

    Game* o_game = new Game(3,3);
    o_game->startGame();
    o_game->restartGame();
    delete o_game;

}

int main()
{
    //IntegrationTest();
    IntegrationGame();

    return 0;
}
