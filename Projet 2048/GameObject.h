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
	GameObject(int number); // constructor

	void setPath(); // m�thode pour d�finir le chemin le chemin
	std::string getPath(); // m�thode pour r�cup�rer le chemin
};