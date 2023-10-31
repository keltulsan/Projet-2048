#pragma once

#include <vector>

class Test {
	/* Classe pour faire les testes d'int�grations */
public:
	Test(); // constructor
	
	void gridCreateCopy(); // m�thode pour tester la copie d'une grille

	/* M�thodes pour tester les d�placements */
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	/* M�thodes pour tester les d�placements de toutes la grille */
	void moveUpSide();
	void moveDownSide();
	void moveLeftSide();
	void moveRightSide();
	
	/* M�thodes pour tester les fusions */
	void fusionRight();
	void fusionLeft();
	void fusionUp();
	void fusionDown();

	/* M�thodes pour tester les fusions de toutes la grilles */
	void fusionUpSide();
	void fusionDownSide();
	void fusionLeftSide();
	void fusionRightSide();

	
	/* M�thodes pour tester les d�placements et les fusions de toutes la grille */
	void up();
	void down();
	void left();
	void right();

	void win(); // m�thode pour tester la win
	void lose(); // m�thode pour tester la lose

	void getPath();
	void getTab();
};