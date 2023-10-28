#pragma once

class Tile {
	/* Class pour créer l'intérieur des cases de la grille du 2048 */
private : 
	int value; // la valeur de la case

public :
	Tile(int value); // constructor

	int getValue(); // méthode pour récupérer la valeur de la case
	void setValue(int value); // méthode pour modifier la valeur de la case
};