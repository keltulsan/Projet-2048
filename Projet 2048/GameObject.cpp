#include "GameObject.h"

GameObject::GameObject(int number)
{
	this->number = number;
};

void GameObject::setPath()
{
	std::string start = "Image/Tile_";
	std::string middle = std::to_string(this->number);
	std::string end = ".bmp";
	int size = end.size() + middle.size() + start.size();
	char* buffer = new char[size];
	this->path = "Image/Tile_" + std::to_string(this->number) + ".bmp";
};

char* GameObject::getPath()
{
	int size = this->path.size();
	char* buffer = new char[size];
	strcpy(buffer, path.c_str()); // copie de path
	return buffer;
};