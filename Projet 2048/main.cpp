#include <iostream>
#include "Grid.h"
#include "Tile.h"
#include "Game.h"
#include "Test.h"
#include "GameObject.h"
#include "Window.h"
#include <Windows.h>
#include <vector>

#include <SDL.h>


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int GRID_SIZE = 4;
const int TILE_SIZE = 100;

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

    o_test.getTab();
    o_test.getPath();

}

void IntegrationGame()
{
    srand(time(NULL));

    Game* o_game = new Game(4,4, 1280, 800);
    o_game->startGameGraphic();
    delete o_game;

}

int main(int argc, char** argv) {

    //IntegrationTest();
    IntegrationGame();

    //SDL_Surface* image = SDL_LoadBMP("Image/Tile_32.bmp");
    //if (!image)
    //{
    //    std::cout << "Erreur de chargement de l'image :  " << SDL_GetError();
    //    return -1;
    //}

    //SDL_Texture* monImage = SDL_CreateTextureFromSurface(renderer, image);  //La texture monImage contient maintenant l'image importée
    //SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

  
    return 0;
}