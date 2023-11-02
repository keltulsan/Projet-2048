#include "GameObject.h"

GameObject::GameObject(int number)
{
	/* Constructor */
	this->number = number;
};

void GameObject::setPath()
{
	/* M�thode pour d�finir le chemin */
	this->path = "Image/Tile_" + std::to_string(this->number) + ".bmp";
};

std::string GameObject::getPath()
{
	/* M�thode pour r�cup�rer le chemin */
	return this->path;
};