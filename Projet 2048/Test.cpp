#include "Test.h"
#include "Grid.h"
#include "GameObject.h"

Grid* o_grid = new Grid(4, 4);

Test::Test() {}; // constructor

void Test::gridCreateCopy()
{
	/* M�thode pour tester la copie d'une grille */
	int start[4][4] =
	{
		{0,0,5,0},
		{0,0,0,0},
		{2,0,0,0},
		{4,0,0,3},
	};
	
	int result[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};


	Grid* grid = new Grid(start);
	Grid* grid2 = new Grid(result);
	//grid.display();
	grid2->gridCreateCopy(grid);
	//grid2.display();
	bool isSuccess = grid2->compareVectorTile(grid);
	std::cout << "Test Copy grid: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;
	delete grid;
	delete grid2;
}

/* M�thodes pour tester les d�placements */

void Test::moveUp() 
{
	/* M�thode pour tester les d�placements en haut */
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
	/* M�thode pour tester les d�placements en bas */
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
	/* M�thode pour tester les d�placements � droite */
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
	/* M�thode pour tester les d�placements � gauche */
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

/* ---------------------------------------------------------- */


/* M�thodes pour tester les d�placements de toutes la grille */


void Test::moveUpSide()
{
	/* M�thode pour tester les d�placements de toutes la grille en haut*/
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
	/* M�thode pour tester les d�placements de toutes la grille en bas*/
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
	/* M�thode pour tester les d�placements de toutes la grille � droite */
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
	/* M�thode pour tester les d�placements de toutes la grille � gauche */
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

/* ---------------------------------------------------------- */

/* M�thodes pour tester les fusions */

void Test::fusionRight()
{
	/* M�thode pour tester les fusions � droite */
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
	/* M�thode pour tester les fusions � gauche */
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
	/* M�thode pour tester les fusions en haut */
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
	/* M�thode pour tester les fusions en bas */
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

/* ---------------------------------------------------------- */

/* M�thodes pour tester les fusions de toutes la grilles */

void Test::fusionUpSide()
{
	/* M�thode pour tester les fusions en haut de toutes la grilles */
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
	/* M�thode pour tester les fusions en bas de toutes la grilles */
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
	/* M�thode pour tester les fusions � gauche de toutes la grilles */
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
	/* M�thode pour tester les fusions � droite de toutes la grilles */
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

/* ---------------------------------------------------------- */

/* M�thodes pour tester les d�placements et les fusions de toutes la grille */

void Test::right()
{
	/* M�thode pour tester les d�placements et les fusions de toutes la grille vers la droite */
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
	/* M�thode pour tester les d�placements et les fusions de toutes la grille vers la gauche */
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
	/* M�thode pour tester les d�placements et les fusions de toutes la grille vers le haut */
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
	/* M�thode pour tester les d�placements et les fusions de toutes la grille vers le bas */
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

/* ---------------------------------------------------------- */


void Test::win()
{
	/* M�thode pour tester la win */
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

void Test::lose()
{
	/* M�thode pour tester la lose */
	int start[4][4] =
	{
		{2,4,8,16},
		{4,8,16,2},
		{8,16,2,4},
		{16,2,4,8},
	};

	Grid grid(start);
	bool isSuccess = grid.conditionGameLose();
	std::cout << "Test Lose: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;
}


void Test::getPath()
{
	/* M�thode pour tester la lose */
	std::string result = "Image/Tile_2.bmp";

	GameObject gameObject(2);
	gameObject.setPath();
	bool isSuccess = gameObject.getPath() == result;
	std::cout << "Test GetPath: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;
}
