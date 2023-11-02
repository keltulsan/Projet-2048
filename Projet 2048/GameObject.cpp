#include "GameObject.h"

GameObject::GameObject(int number)
{
	/* Constructor */
	this->number = number;
};

void GameObject::setPath()
{
	/* Méthode pour définir le chemin */
	this->path = "Image/Tile_" + std::to_string(this->number) + ".bmp";
};

std::string GameObject::getPath()
{
	/* Méthode pour récupérer le chemin */
	return this->path;
};