#pragma once

#include <string>
#include <cstring>
#include <iostream>

class GameObject 
{
	/* Classe qui va définir les différentes tuiles de la grille */
private:
	int number;
	std::string path;

public:
	GameObject(int number); // constructor

	void setPath(); // méthode pour définir le chemin le chemin
	std::string getPath(); // méthode pour récupérer le chemin
};