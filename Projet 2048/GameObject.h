#pragma once

#include <string>
#include <cstring>
#include <iostream>

class GameObject 
{
	/* Classe qui va définir les différentes tuiles de la grille */
private:
	int number;
	char* path;

public:
	GameObject(int number);

	void setPath();
	char* getPath();
};