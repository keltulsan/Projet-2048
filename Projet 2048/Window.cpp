#include "Window.h"

Window::Window(int screenWidth, int screenHeight, int nbColonnes, int nbLignes, int tileSizeX, int tileSizeY, int interTileoffset, int borderOffset)
{
    /* Constructor */
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
    this->initSDL();
    this->initGrid();
}

void Window::initSDL() {
    /* Méthode pour initialiser SDL */
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

void Window::initGrid()
{
    /* Méthode pour initialiser l'affichage de la grille */
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


void Window::renderImage(int number, int x, int y, int h, int w, SDL_Texture** imageTexture)
{
    /* Méthode pour afficher unos chiffre */
    SDL_Rect tile; // box dans laquelle sera afficher nos chiffres
    tile.x = x;
    tile.y = y;
    tile.h = h;
    tile.w = w;

    /* Vérification du nombre choisi pour afficher l'image en question */
    switch (number)
    {
    case 2:
        SDL_RenderCopy(this->renderer, imageTexture[Case2], NULL, &tile); // affichage d'une image
        break;

    case 4:
        SDL_RenderCopy(this->renderer, imageTexture[Case4], NULL, &tile);
        break;

    case 8:
        SDL_RenderCopy(this->renderer, imageTexture[Case8], NULL, &tile);
        break;

    case 16:
        SDL_RenderCopy(this->renderer, imageTexture[Case16], NULL, &tile);
        break;

    case 32:
        SDL_RenderCopy(this->renderer, imageTexture[Case32], NULL, &tile);
        break;

    case 64:
        SDL_RenderCopy(this->renderer, imageTexture[Case64], NULL, &tile);
        break;

    case 128:
        SDL_RenderCopy(this->renderer, imageTexture[Case128], NULL, &tile);
        break;

    case 256:
        SDL_RenderCopy(this->renderer, imageTexture[Case256], NULL, &tile);
        break;

    case 512:
        SDL_RenderCopy(this->renderer, imageTexture[Case512], NULL, &tile);
        break;

    case 1024:
        SDL_RenderCopy(this->renderer, imageTexture[Case1024], NULL, &tile);
        break;

    case 2048:
        SDL_RenderCopy(this->renderer, imageTexture[Case2048], NULL, &tile);
        break;
    }
}

void Window::graphicDisplay(Grid* o_grid, SDL_Texture** imageTexture)
{
    /* Méthode pour afficher la grille de jeu */
    int height = (this->nbColonnes * this->tileSizeY) + ((this->nbColonnes - 1) * this->interTileoffset) + (2 * borderOffset);
    int width = (this->nbLignes * this->tileSizeX) + ((this->nbLignes - 1) * this->interTileoffset) + (2 * borderOffset);
    int startX = ((this->screenWidth - width) / 2) + borderOffset;
    int startY = ((this->screenHeight - height) / 2) + borderOffset;

    this->initGrid(); 

    /* Boucle for pour position des images à afficher*/
    for (int i = 0; i < this->nbColonnes; i++) 
    {
        for (int j = 0; j < this->nbLignes; j++)
        {
            this->renderImage(o_grid->getTab()[i][j]->getValue(), startX, startY, this->tileSizeX, this->tileSizeY, imageTexture);
            startX += this->tileSizeX + this->interTileoffset; // modification des coordonnées de départs pour l'affichage
        }
        startY += this->tileSizeY + this->interTileoffset; // modification des coordonnées de départs pour l'affichage
        startX = ((this->screenWidth - width) / 2) + borderOffset; // modification des coordonnées de départs pour l'affichage
    }
    SDL_RenderPresent(this->renderer); // affichage de la grille de jeu
}

SDL_Renderer* Window::getRenderer()
{
    /* Méthode pour récupérer un renderer */
    return this->renderer;
}

SDL_Window* Window::getWindow()
{
    /* Méthode pour récupérer une window */
    return this->window;
}

void Window::cleanUpSDL() {
    /* Méthode pour détruire SDL */
    SDL_DestroyRenderer(this->renderer); // destruction du renderer
    SDL_DestroyWindow(this->window);// destruction de la window
    SDL_Quit(); // quite le moteur de rendu visuel
}

