// KnightsTour.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <time.h>


#include "board.h"
#include "space.h"
#include "knight.h"

using namespace std;

/*





*/

int main()
{
	knight knight;
	board board;
	space inital;

	srand(time(NULL));


	knight.x = rand() % (7 - 0 + 1) + 0;
	knight.y = rand() % (7 - 0 + 1) + 0;
	board.init();
	board.display();
	knight.findMoves(board,1,inital);

	/*for (space move : knight.availableMoves)
	{
		cout << "FOUND "<< move.x << " " << move.y << endl;
	}*/

}


