#include <iostream>
#include "Grid.h"
#include "Tile.h"
#include <Windows.h>

#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

int main()
{
    
    Grid* o_grid = new Grid(4, 4);
    o_grid->display();
    o_grid->changeValueWithCoordinates(4, 4, 9);

    delete o_grid;

    //int c = 0;
    //while (1)
    //{
    //    c = 0;

    //    switch ((c = _getch())) 
    //    {
    //    case KEY_UP:
    //        cout << endl << "Up" << endl;//key up
    //        break;
    //    case KEY_DOWN:
    //        cout << endl << "Down" << endl;   // key down
    //        break;
    //    case KEY_LEFT:
    //        cout << endl << "Left" << endl;  // key left
    //        break;
    //    case KEY_RIGHT:
    //        cout << endl << "Right" << endl;  // key right
    //        break;
    //    default:
    //        continue;
    //    }

    //}

}

