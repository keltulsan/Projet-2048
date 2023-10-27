#pragma once

#include <vector>

class Test {
public:
	Test();
	
	void gridCreateCopy();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void moveUpSide();
	void moveDownSide();
	void moveLeftSide();
	void moveRightSide();
	
	void fusionRight();
	void fusionLeft();
	void fusionUp();
	void fusionDown();
	void fusionUpSide();
	void fusionDownSide();
	void fusionLeftSide();
	void fusionRightSide();

	void up();
	void down();
	void left();
	void right();

	void win();
	void loose();
};