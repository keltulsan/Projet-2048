#pragma once

#include <vector>

class Test {
	/* Classe pour faire les testes d'intégrations */
public:
	Test(); // constructor
	
	void gridCreateCopy(); // méthode pour tester la copie d'une grille

	/* Méthodes pour tester les déplacements */
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	/* Méthodes pour tester les déplacements de toutes la grille */
	void moveUpSide();
	void moveDownSide();
	void moveLeftSide();
	void moveRightSide();
	
	/* Méthodes pour tester les fusions */
	void fusionRight();
	void fusionLeft();
	void fusionUp();
	void fusionDown();

	/* Méthodes pour tester les fusions de toutes la grilles */
	void fusionUpSide();
	void fusionDownSide();
	void fusionLeftSide();
	void fusionRightSide();

	
	/* Méthodes pour tester les déplacements et les fusions de toutes la grille */
	void up();
	void down();
	void left();
	void right();

	void win(); // méthode pour tester la win
	void lose(); // méthode pour tester la lose

	void getPath();
	void getTab();
};