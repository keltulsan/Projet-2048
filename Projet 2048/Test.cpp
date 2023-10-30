#include "Test.h"
#include "Grid.h"
#include "GameObject.h"

Grid* o_grid = new Grid(4, 4);

Test::Test() {}; // constructor

void Test::gridCreateCopy()
{
	/* Méthode pour tester la copie d'une grille */
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

/* Méthodes pour tester les déplacements */

void Test::moveUp() 
{
	/* Méthode pour tester les déplacements en haut */
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
	/* Méthode pour tester les déplacements en bas */
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
	/* Méthode pour tester les déplacements à droite */
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
	/* Méthode pour tester les déplacements à gauche */
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


/* Méthodes pour tester les déplacements de toutes la grille */


void Test::moveUpSide()
{
	/* Méthode pour tester les déplacements de toutes la grille en haut*/
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
	/* Méthode pour tester les déplacements de toutes la grille en bas*/
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
	/* Méthode pour tester les déplacements de toutes la grille à droite */
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
	/* Méthode pour tester les déplacements de toutes la grille à gauche */
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

/* Méthodes pour tester les fusions */

void Test::fusionRight()
{
	/* Méthode pour tester les fusions à droite */
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
	/* Méthode pour tester les fusions à gauche */
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
	/* Méthode pour tester les fusions en haut */
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
	/* Méthode pour tester les fusions en bas */
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

/* Méthodes pour tester les fusions de toutes la grilles */

void Test::fusionUpSide()
{
	/* Méthode pour tester les fusions en haut de toutes la grilles */
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
	/* Méthode pour tester les fusions en bas de toutes la grilles */
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
	/* Méthode pour tester les fusions à gauche de toutes la grilles */
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
	/* Méthode pour tester les fusions à droite de toutes la grilles */
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

/* Méthodes pour tester les déplacements et les fusions de toutes la grille */

void Test::right()
{
	/* Méthode pour tester les déplacements et les fusions de toutes la grille vers la droite */
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
	/* Méthode pour tester les déplacements et les fusions de toutes la grille vers la gauche */
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
	/* Méthode pour tester les déplacements et les fusions de toutes la grille vers le haut */
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
	/* Méthode pour tester les déplacements et les fusions de toutes la grille vers le bas */
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
	/* Méthode pour tester la win */
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
	/* Méthode pour tester la lose */
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
	/* Méthode pour tester la lose */
	std::string result = "Image/Tile_2.bmp";

	GameObject gameObject(2);
	gameObject.setPath();
	bool isSuccess = gameObject.getPath() == result;
	std::cout << "Test GetPath: " << (isSuccess ? "SUCCESS" : "FAILURE") << std::endl;
}
