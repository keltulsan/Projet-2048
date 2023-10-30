#pragma once

#include <string>
#include <cstring>
#include <iostream>

class GameObject 
{
	/* Classe qui va d�finir les diff�rentes tuiles de la grille */
private:
	int number;
	char* path;

public:
	GameObject(int number);

	void setPath();
	char* getPath();
};