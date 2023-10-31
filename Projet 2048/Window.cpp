#include "Window.h"

Window::Window(int nbColonnes, int nbLignes, int TileSixeX, int TileSixeY, int screenWidth, int screenHeight)
{
    this->screenHeight = screenHeight;
    this->screenWidth = screenWidth;
	this->nbColonnes = nbColonnes;
	this->nbLignes = nbLignes;
	this->TileSixeX = TileSixeX;
	this->TileSixeY = TileSixeY;
    this->window = NULL;
    this->renderer = NULL;
}

void Window::initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    this->window = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->screenWidth, this->screenHeight, SDL_WINDOW_SHOWN);
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

void Window::startGraphicRender()
{
    this->initSDL();

    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            SDL_RenderPresent(this->renderer);
        }
    }

    this->cleanUpSDL();
}

void Window::gridDisplay()
{
    GameObject* o_gameObject = new GameObject(2);
    o_gameObject->setPath();

    SDL_Surface* image = SDL_LoadBMP(o_gameObject->getPath().c_str()); // envoie d'un string qui est ensuite modifier en char* avec la fonction c_str()

    SDL_Texture* monImage = SDL_CreateTextureFromSurface(this->renderer, image);  //La texture monImage contient maintenant l'image importée
    SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

}