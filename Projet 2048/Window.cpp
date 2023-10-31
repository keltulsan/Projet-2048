#include "Window.h"

Window::Window(int screenWidth, int screenHeight,int nbColonnes, int nbLignes, int tileSizeX, int tileSizeY, int interTileoffset, int borderOffset)
{
    this->screenHeight = screenHeight;
    this->screenWidth = screenWidth;
	this->nbColonnes = nbColonnes;
	this->nbLignes = nbLignes;
    this->tileSizeX = tileSizeX;
    this->tileSizeY = tileSizeY;
    this->interTileoffset = interTileoffset;
    this->borderOffset = borderOffset;
    this->window = NULL;
    this->renderer = NULL;
    this->texture = NULL;
    this->surface = NULL;
}

void Window::initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    this->window = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->screenWidth, this->screenHeight, SDL_WINDOW_OPENGL);
    if (this->window == NULL) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == NULL) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void Window::cleanUpSDL() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

//typedef enum TextureLabel
//{
//    Case0 = 0,
//    Case2 = 1,
//    Case4 = 2,
//};
//SDL_Texture* textures[2];
//
//textures[Case0];
//
//textures[Case2];


void Window::renderImage(int number, int x, int y, int h, int w)
{
    GameObject* o_gameObject = new GameObject(number);
    o_gameObject->setPath();

    SDL_Rect tile;
    tile.x = x;
    tile.y = y;
    tile.h = h;
    tile.w = w;

    if (number != 0)
    {

        SDL_Surface* image = SDL_LoadBMP(o_gameObject->getPath().c_str()); // envoie d'un string qui est ensuite modifier en char* avec la fonction c_str()
        SDL_Texture* monImage = SDL_CreateTextureFromSurface(this->renderer, image);  //La texture monImage contient maintenant l'image importée

        SDL_RenderCopy(this->renderer, monImage, NULL, &tile);
        SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

        delete o_gameObject;
    }
    else {
        SDL_SetRenderDrawColor(this->renderer, 159, 159, 159, 180);
        SDL_RenderFillRect(this->renderer, &tile);
    }

}

void Window::initGrid()
{
    int height = (this->nbColonnes * this->tileSizeY) + ((this->nbColonnes - 1) * this->interTileoffset) + (2 * borderOffset);
    int width = (this->nbLignes * this->tileSizeX) + ((this->nbLignes - 1) * this->interTileoffset) + (2 * borderOffset);
    int startX = (this->screenWidth - width) / 2;
    int startY = (this->screenHeight - height) / 2;

    int startTileX = startX + borderOffset;
    int startTileY = startY + borderOffset;

    SDL_SetRenderDrawColor(this->renderer, 118, 111, 100, 255);
    SDL_RenderClear(this->renderer);

    SDL_Rect backGrid;
    backGrid.x = startX;
    backGrid.y = startY;
    backGrid.h = height;
    backGrid.w = width;

    SDL_SetRenderDrawColor(this->renderer, 159, 159, 159, 180);
    SDL_RenderFillRect(this->renderer, &backGrid);

    for (int i = 0; i < this->nbColonnes; i++)
    {
        for (int j = 0; j < this->nbLignes; j++)
        {
            SDL_Rect tile;
            tile.x = startTileX;
            tile.y = startTileY;
            tile.h = this->tileSizeY;
            tile.w = this->tileSizeX;

            SDL_SetRenderDrawColor(this->renderer, 200, 200, 200, 200);
            SDL_RenderFillRect(this->renderer, &tile);

            startTileX += this->tileSizeX + this->interTileoffset;
        }
        startTileY += this->tileSizeY + this->interTileoffset;
        startTileX = startX + borderOffset;
    }
}


void Window::graphicDisplay(Grid* o_grid)
{
    int height = (this->nbColonnes * this->tileSizeY) + ((this->nbColonnes - 1) * this->interTileoffset) + (2 * borderOffset);
    int width = (this->nbLignes * this->tileSizeX) + ((this->nbLignes - 1) * this->interTileoffset) + (2 * borderOffset);
    int startX = ((this->screenWidth - width) / 2) + borderOffset;
    int startY = ((this->screenHeight - height) / 2) + borderOffset;

    for (int i = 0; i < this->nbColonnes; i++)
    {
        for (int j = 0; j < this->nbLignes; j++)
        {
            this->renderImage(o_grid->getTab()[i][j]->getValue(), startX, startY, this->tileSizeX, this->tileSizeY);
            startX += this->tileSizeX + this->interTileoffset;
        }
        startY += this->tileSizeY + this->interTileoffset;
        startX = ((this->screenWidth - width) / 2) + borderOffset;
    }
    SDL_RenderPresent(this->renderer);

}
