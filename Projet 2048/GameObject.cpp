#include "GameObject.h"

GameObject::GameObject(int number)
{
	this->number = number;
};

void GameObject::setPath()
{
	this->path = "Image/Tile_" + std::to_string(this->number) + ".bmp";
};

std::string GameObject::getPath()
{
	return this->path;
};