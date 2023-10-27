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
		{2,0,0,0},
		{4,0,0,0},
	};

	int result[4][4] =
	{
		{2,0,0,0},
		{4,0,0,0},
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
		{2,0,0,0},
		{0,0,0,0},
		{4,0,0,0},
	};

	int result[4][4] =
	{
		{0,0,0,0},
		{2,0,0,0},
		{2,0,0,0},
		{4,0,0,0},
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
		{4,4,0,2},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	int result[4][4] =
	{
		{4,4,2,0},
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
		{0,2,0,2},
		{0,2,0,0},
		{2,0,4,0},
		{2,2,2,2},
	};

	int result[4][4] =
	{
		{2,2,4,2},
		{2,2,2,2},
		{0,2,0,0},
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
		{0,4,0,0},
		{0,4,0,0},
		{0,4,0,0},
	};

	int result[4][4] =
	{
		{0,2,0,0},
		{0,4,0,0},
		{0,4,0,0},
		{2,4,2,2},
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
		{0,0,0,0},
		{2,0,0,0},
		{0,0,0,0},
	};

	int result[4][4] =
	{
		{0,0,0,2},
		{0,0,0,0},
		{0,0,0,2},
		{0,0,0,0},
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
		{0,0,2,4},
		{0,0,0,8},
		{0,0,0,2},
	};

	int result[4][4] =
	{
		{2,0,0,0},
		{2,4,0,0},
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

void Test::fusionRight()
{
	int start[4][4] =
	{
		{0,4,4,2},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	int result[4][4] =
	{
		{0,0,8,2},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.fusionRight(0);
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Fusion Right: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::fusionLeft()
{
	int start[4][4] =
	{
		{2,2,2,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	int result[4][4] =
	{
		{4,0,2,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.fusionLeft(0);
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Fusion Left: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::fusionUp()
{
	int start[4][4] =
	{
		{2,0,0,0},
		{2,0,0,0},
		{4,0,0,0},
		{4,0,0,0},
	};

	int result[4][4] =
	{
		{4,0,0,0},
		{0,0,0,0},
		{4,0,0,0},
		{4,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.fusionUp(0);
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Fusion Up: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::fusionDown()
{
	int start[4][4] =
	{
		{0,0,0,0},
		{2,0,2,0},
		{2,0,0,0},
		{0,0,2,0},
	};

	int result[4][4] =
	{
		{0,0,0,0},
		{0,0,2,0},
		{4,0,0,0},
		{0,0,2,0},
	};

	Grid grid(start);
	//grid.display();
	grid.fusionDown(0);
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Fusion Down: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::fusionUpSide()
{
	int start[4][4] =
	{
		{2,0,0,0},
		{2,0,0,0},
		{2,0,0,0},
		{0,0,0,0},
	};

	int result[4][4] =
	{
		{4,0,0,0},
		{0,0,0,0},
		{2,0,0,0},
		{0,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.fusionUpSide();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Fusion Up Side: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::fusionDownSide()
{
	int start[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{2,2,2,2},
		{2,2,2,2},
	};

	int result[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{4,4,4,4},
	};

	Grid grid(start);
	//grid.display();
	grid.fusionDownSide();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Fusion Down Side: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::fusionLeftSide()
{
	int start[4][4] =
	{
		{4,2,2,0},
		{16,16,0,0},
		{2,4,0,0},
		{8,4,0,0},
	};

	int result[4][4] =
	{
		{4,4,0,0},
		{32,0,0,0},
		{2,4,0,},
		{8,4,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.fusionLeftSide();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Fusion Left Side: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::fusionRightSide()
{
	int start[4][4] =
	{
		{0,0,2,2},
		{0,0,0,0},
		{0,0,8,2},
		{0,0,4,4},
	};

	int result[4][4] =
	{
		{0,0,0,4},
		{0,0,0,0},
		{0,0,8,2},
		{0,0,0,8},
	};

	Grid grid(start);
	//grid.display();
	grid.fusionRightSide();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Fusion Right Side: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::right()
{
	int start[4][4] =
	{
		{2,0,2,2},
		{8,4,4,2},
		{0,0,8,2},
		{0,0,4,4},
	};

	int result[4][4] =
	{
		{0,0,2,4},
		{0,8,8,2},
		{0,0,8,2},
		{0,0,0,8},
	};

	Grid grid(start);
	//grid.display();
	grid.right();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Play Right: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::left()
{
	int start[4][4] =
	{
		{2,0,0,0},
		{0,0,4,0},
		{0,8,0,0},
		{0,0,0,16},
	};

	int result[4][4] =
	{
		{2,0,0,0},
		{4,0,0,0},
		{8,0,0,0},
		{16,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.left();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Play Left: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::up()
{
	int start[4][4] =
	{
		{2,2,2,2},
		{2,2,2,2},
		{2,2,2,2},
		{2,2,2,2},
	};

	int result[4][4] =
	{
		{4,4,4,4},
		{2,2,2,2},
		{2,2,2,2},
		{0,0,0,0},
	};

	Grid grid(start);
	//grid.display();
	grid.up();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Play Up: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::down()
{
	int start[4][4] =
	{
		{4,0,0,2},
		{2,0,2,2},
		{4,4,0,4},
		{0,0,16,8},
	};

	int result[4][4] =
	{
		{0,0,0,0},
		{4,0,0,4},
		{2,0,2,4},
		{4,4,16,8},
	};

	Grid grid(start);
	//grid.display();
	grid.down();
	//grid.display();
	bool isSuccess = grid.compare(result);
	std::cout << "Test Play Down: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}

void Test::win()
{
	int start[4][4] =
	{
		{4,0,0,2},
		{2,0,2,2},
		{4,1024,0,4},
		{0,1024,16,8},
	};

	Grid grid(start);
	//grid.display();
	grid.fusionDownSide();
	//grid.display();
	bool isSuccess = grid.conditionGameWin();
	std::cout << "Test Win: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;

}




