#pragma once
#include "board.h"
#include "space.h"

#include <vector>
#include <iostream>


class knight
{
public:
	int x;
	int y;
	int paths = 0;
	int steps = 0;
	space exhausted;

	void move(board tempBoard, space current, int step)
	{


		tempBoard.spaces[current.x][current.y].visited = true;
		tempBoard.spaces[current.x][current.y].step = step;
		steps++;

		if (step == 64)
			system("PAUSE");
		step++;
		x = current.x;
		y = current.y;
		//if(step >50)
		tempBoard.display();
		findMoves(tempBoard, step, current);

	}

	void findMoves(board search, int step, space current)
	{
		vector<space> availableMoves;
		int xTranslation;
		int yTranslation;


		xTranslation = 2;
		yTranslation = 1;


		// What was I thinking when I wrote this???

		for (int c = 0; c < 2; c++)
		{
			if (c == 1)
				xTranslation = -2;

			for (int i = 0; i < 2; i++)
			{
				if (i == 1)
					yTranslation = -1;

				if (!search.spaces[x + xTranslation][y + yTranslation].visited && x + xTranslation <= 7 && y + yTranslation <= 7 && x + xTranslation >= 0 && y + yTranslation >= 0)
					availableMoves.push_back(search.spaces[x + xTranslation][y + yTranslation]);

				if (!search.spaces[x + yTranslation][y + xTranslation].visited && x + yTranslation <= 7 && y + xTranslation <= 7 && x + yTranslation >= 0 && y + xTranslation >= 0)
					availableMoves.push_back(search.spaces[x + yTranslation][y + xTranslation]);
			}

			paths += availableMoves.size();



			for (space movespace : availableMoves)
			{
				board tempBoard;
				tempBoard.spaces[movespace.x][movespace.y].visited = true;
				bool skipmove = false;

				for (int x = 0; x <= 7; x++)
				{
					for (int y = 0; y <= 7; y++)
					{
						if (tempBoard.spaces[x][y].isBlocked(tempBoard.spaces,x,y) && step < 63)
						{
							skipmove = true;
						}
					}
				}

				if (!skipmove)
				{
					exhausted = current;
					cout << endl << "STEP " << step << endl;
					cout << paths << " PATHS" << endl;
					cout << "Last exhausted node: " << exhausted.x << " " << exhausted.y << " At step " << exhausted.step;
					cout << endl << steps << " Total Steps";

					move(search, movespace, step);
					//cout << "BACKTRACK" << endl;
				}
				else
				{
					//cout << "FLAG: BLOCKED MOVE "<< movespace.x <<" "<< movespace.y << endl;
				}

				skipmove = false;
				paths--;
			}

			

		}
		exhausted.step = step;
	}

};



