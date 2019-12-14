#pragma once
#include "space.h"
#include <iomanip>
#include <iostream>
using namespace std;
class board
{
public:
	space spaces[8][8];


	void display()
	{
		//system("CLS");
		if (system("CLS")) system("clear");
		x = 0;
		y = 0;
		while (x <= 7)
		{

			while (y <= 7)
			{
				cout << setw(2) << spaces[x][y].step << " | ";
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

