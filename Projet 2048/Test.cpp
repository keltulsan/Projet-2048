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
	grid.movement(0, 0, 1, 0);
	bool isSuccess = grid.compare(result);
	std::cout << "Test Result: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}