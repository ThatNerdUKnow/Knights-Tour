#pragma once

using namespace std;
#include "board.h"
#include <vector>




class space
{
public:
	int step = 0;
	bool visited = false;
	int x;
	int y;

	bool blockingNeighbors(space search[8][8])
	{
  		vector<space> availableMoves;
		int xTranslation = 2;
		int yTranslation = 1;
		bool output = false;

		for (int i = 0; i < 2; i++)
		{
			if (i == 1)
				yTranslation = -1;

			if (!search[x + xTranslation][y + yTranslation].visited && x + xTranslation <= 7 && y + yTranslation <= 7 && x + xTranslation >= 0 && y + yTranslation >= 0 && search[x+xTranslation][y+yTranslation].step == 0)
				availableMoves.push_back(search[x + xTranslation][y + yTranslation]);

			if (availableMoves.size() > 0)
			{
				availableMoves[availableMoves.size() - 1].x = x + xTranslation;
				availableMoves[availableMoves.size() - 1].y = y + yTranslation;
			}

			if (!search[x + yTranslation][y + xTranslation].visited && x + yTranslation <= 7 && y + xTranslation <= 7 && x + yTranslation >= 0 && y + xTranslation >= 0 && search[x + yTranslation][y + xTranslation].step == 0)
				availableMoves.push_back(search[x + yTranslation][y + xTranslation]);

			if (availableMoves.size() > 0)
			{
				availableMoves[availableMoves.size() - 1].x = x + yTranslation;
				availableMoves[availableMoves.size() - 1].y = y + xTranslation;
			}
		}

		// scan neighbors to see if they are blocked
		for (space neighbor : availableMoves)
		{
			if (neighbor.isBlocked(search,neighbor.x,neighbor.y))
				return true;
		}

		
		return false;
	}

	bool isBlocked(space search[8][8],int x, int y)
	{
		
		vector<space> availableMoves;
		int xTranslation = 2;
		int yTranslation = 1;
		space checkingSpace;
		
		for (int c = 0; c < 2; c++)
		{
			if (c == 1)
				xTranslation = -2;
			for (int i = 0; i < 2; i++)
			{

				if (i == 1)
					yTranslation = -1;

				if (x + xTranslation <= 7 && y + yTranslation <= 7 && x + xTranslation >= 0 && y + yTranslation >= 0)
				{


					checkingSpace = search[x + xTranslation][y + yTranslation];

					if (!checkingSpace.visited && checkingSpace.step == 0)
						availableMoves.push_back(search[x + xTranslation][y + yTranslation]);

				}



				if (x + yTranslation <= 7 && y + xTranslation <= 7 && x + yTranslation >= 0 && y + xTranslation >= 0)
				{
					checkingSpace = search[x + yTranslation][y + xTranslation];

					if (!checkingSpace.visited && checkingSpace.step == 0)
						availableMoves.push_back(search[x + yTranslation][y + xTranslation]);
				}



			}
		}

		if (availableMoves.size() == 0)
			return true;
		else
			return false;
	}
};
