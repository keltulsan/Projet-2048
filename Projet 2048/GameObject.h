#pragma once

#include <string>
#include <cstring>
#include <iostream>

class GameObject 
{
	/* Classe qui va d�finir les diff�rentes tuiles de la grille */
private:
	int number;
	std::string path;

public:
	GameObject(int number);

	void setPath();
	std::string getPath();
};