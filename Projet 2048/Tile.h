#pragma once

class Tile {
	/* Class pour cr�er l'int�rieur des cases de la grille du 2048 */
private : 
	int value; // la valeur de la case

public :
	Tile(int value); // constructor

	int getValue(); // m�thode pour r�cup�rer la valeur de la case
	void setValue(int value); // m�thode pour modifier la valeur de la case
};