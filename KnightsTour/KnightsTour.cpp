// KnightsTour.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct space
{
	int step = 0;
	bool visited = false;
	int x;
	int y;
};
class board
{
public:
	space spaces[8][8];

	
	void display()
	{
		system("CLS");
		x = 0;
		y = 0;
		while (x <= 7)
		{

			while (y <= 7)
			{
				cout << setw(2)  << spaces[x][y].step << " | ";
				y++;
			}
			cout << endl;
			x++;
			y = 0;
		}
	}

	void init()
	{
		while (x <= 7)
		{
			
			while (y <= 7)
			{
				spaces[x][y].x = x;
				spaces[x][y].y = y;
				spaces[x][y].step = 0;
				y++;
			}
			x++;
			y = 0;
		}
	}

private:
	int x = 0;
	int y = 0;
};
class knight
{
public:
	int x;
	int y;
	int paths = 0;

	void move(board tempBoard, space current, int step)
	{
		
		
		tempBoard.spaces[current.x][current.y].visited = true;
		tempBoard.spaces[current.x][current.y].step = step;
		if (step == 64)
			system("PAUSE");
		step++;
		x = current.x;
		y = current.y;
		tempBoard.display();
		findMoves(tempBoard,step);

	}

	void findMoves(board search, int step)
	{
		vector<space> availableMoves;
		int xTranslation;
		int yTranslation;

		xTranslation = 2;
		yTranslation = 1;
		for (int c = 0; c < 2; c++)
		{
			if (c == 1)
				xTranslation = -2;

			for (int i = 0; i < 2; i++)
			{
				if (i == 1)
					yTranslation = -1;

				if (!search.spaces[x + xTranslation][y + yTranslation].visited && x+xTranslation <=7 && y+yTranslation <=7 && x+xTranslation >=0 && y+yTranslation >=0)
					availableMoves.push_back(search.spaces[x + xTranslation][y + yTranslation]);
				
				if (!search.spaces[x + yTranslation][y + xTranslation].visited&& x+yTranslation <=7 && y+xTranslation <=7&& x+yTranslation >=0 && y+xTranslation >=0)
					availableMoves.push_back(search.spaces[x + yTranslation][y + xTranslation]);
			}

			paths += availableMoves.size();
			
			for (space movespace : availableMoves)
			{
				cout << endl << "STEP " << step << endl;
				cout << paths << " PATHS" << endl;
				move(search, movespace,step);
				paths--;
				
			}
		}
		
	}

};



int main()
{
	knight knight;
	board board;

	knight.x = 5;
	knight.y = 5;
	board.init();
	board.display();
	knight.findMoves(board,1);

	/*for (space move : knight.availableMoves)
	{
		cout << "FOUND "<< move.x << " " << move.y << endl;
	}*/

}


