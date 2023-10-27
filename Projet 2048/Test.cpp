#include "Test.h"
#include "Grid.h"

Grid* o_grid = new Grid(4, 4);

Test::Test() {};

void Test::gridSetUp() {
}
void Test::randomSetUp() {
}
void Test::fusion() {
}
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
	grid.moveUp();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Result Move Up: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

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
	grid.moveDown();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Result Move Down: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

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
	grid.moveRight();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Result Move Right: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

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
	grid.moveLeft();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Result Move Left: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}
