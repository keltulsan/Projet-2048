#include "Test.h"
#include "Grid.h"

Grid* o_grid = new Grid(4, 4);

Test::Test() {};

void Test::moveUp() 
{
	int start[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{2,0,0,0},
	};

	int result[4][4] =
	{
		{2,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.moveUp(0);
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Move Up: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}
void Test::moveDown()
{
	int start[4][4] =
	{
		{2,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	int result[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{2,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.moveDown(0);
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Move Down: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}
void Test::moveRight()
{
	int start[4][4] =
	{
		{2,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	int result[4][4] =
	{
		{0,0,0,2},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.moveRight(0);
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Move Right: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}
void Test::moveLeft()
{
	int start[4][4] =
	{
		{0,0,0,2},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	int result[4][4] =
	{
		{2,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.moveLeft(0);
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Move Left: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::moveUpSide()
{
	int start[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{2,2,2,2},
	};

	int result[4][4] =
	{
		{2,2,2,2},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.moveUpSide();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Move Up Side: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}
void Test::moveDownSide()
{
	int start[4][4] =
	{
		{2,2,2,2},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	int result[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{2,2,2,2},
	};

	Grid grid(start);
	//grid.display();
	grid.moveDownSide();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Move Down Side: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}
void Test::moveRightSide()
{
	int start[4][4] =
	{
		{2,0,0,0},
		{2,0,0,0},
		{2,0,0,0},
		{2,0,0,0},
	};

	int result[4][4] =
	{
		{0,0,0,2},
		{0,0,0,2},
		{0,0,0,2},
		{0,0,0,2},
	};

	Grid grid(start);
	//grid.display();
	grid.moveRightSide();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Move Right Side: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}
void Test::moveLeftSide()
{
	int start[4][4] =
	{
		{0,0,0,2},
		{0,0,0,4},
		{0,0,0,8},
		{0,0,0,2},
	};

	int result[4][4] =
	{
		{2,0,0,0},
		{4,0,0,0},
		{8,0,0,0},
		{2,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.moveLeftSide();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Move Left Side: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::fusion()
{
	int start[4][4] =
	{
		{2,2,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	int result[4][4] =
	{
		{4,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.fusion(0, 0, 0, 1);
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Fusion: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}



