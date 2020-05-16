#pragma once
#include"Cell.h"
#include"graphics.h"
#include"Dice.h"
#include<iostream>
using namespace std;
class Board
{
public:
	Cell Cs[56];
	Board() {}
	void Display()
	{
		initwindow(1900, 1000, "Ludo");

		for (int ri = 0; ri < 20; ri++)
		{
			for (int ci = 0; ci < 10; ci++)
			{
				if (ri == 0 || ri == 19 || ci == 0 || ci == 9)
					bar(ri * 80, ci * 80, (ri + 1) * 80 - 1, (ci + 1) * 80 - 1);
			}
		}
		setfillstyle(SOLID_FILL, 4);	//Red
		bar(80, 80, 239, 239);
		setfillstyle(SOLID_FILL, 1);    //Blue
		bar(80, 560, 239, 719);
		setfillstyle(SOLID_FILL, 2);	//	Green
		bar(17 * 80, 560, 19 * 80 - 1, 719);

		setfillstyle(SOLID_FILL, 3);     //cyan
		bar(1360, 80, 1519, 239);
		setfillstyle(SOLID_FILL, 5);	//purple
		bar(640, 80, 799, 239);
		setfillstyle(SOLID_FILL, 6);		// yelllow
		bar(640, 560, 799, 719);

		//Homes
		setfillstyle(SOLID_FILL, 4);	//Red stay
		bar(80, 0, 159, 79);
		setfillstyle(SOLID_FILL, 4);
		bar(10, 10, 70, 70);
		setfillstyle(SOLID_FILL, 1);	//Blue stay
		bar(160, 9 * 80, 239, 799);
		setfillstyle(SOLID_FILL, 1);
		bar(250, 730, 309, 789);

		setfillstyle(SOLID_FILL, 2);	//	Green //Stay
		bar(18 * 80, 800, 19 * 80 - 1, 719);
		setfillstyle(SOLID_FILL, 2);
		bar(19 * 80 + 10, 9 * 80 + 10, 20 * 80 - 10, 10 * 80 - 10);
		setfillstyle(SOLID_FILL, 3);	//cyan Stay
		bar(17 * 80, 0, 18 * 80 - 1, 79);
		setfillstyle(SOLID_FILL, 3);
		bar(16 * 80 + 10, 10, 17 * 80 - 10, 70);

		setfillstyle(SOLID_FILL, 5);	//Purple Stay
		bar(640, 0, 719, 79);
		setfillstyle(SOLID_FILL, 5);
		bar(570, 10, 630, 70);

		setfillstyle(SOLID_FILL, 6);	//Yellow Stop
		bar(720, 800, 799, 719);
		setfillstyle(SOLID_FILL, 6);
		bar(10 * 80 + 10, 9 * 80 + 10, 11 * 80 - 10, 10 * 80 - 10);
	}
	void DisplayCells()
	{
		for (int i = 0; i < 56; i++)
		{
			Cs[i].Draw();
		}
	}
	void DisplayCells(int start, int end)
	{
		Cs[start].Draw();
		Cs[end].Draw();
	}
	void Highlight(int Start,int ID,Dice D)
	{
		int End[3];
		int size = 0;
		int x;
		for (int i = 0; i < D.size; i++)
		{
			x = D.Ds[i] + Start;
			if (x >= 56)x -= 56;
			if (Cs[Start].Ps[ID][0]->IsLegalMove(D.Ds[i]))
			{
				End[size] = x;
				size++;
			}
		}
		for (int i = 0; i < size; i++)
		{
			Cs[End[i]].Highlight();
		}
	}
	void UnHighlight(int Start, int ID, Dice D)
	{
		int End[3];
		int size = 0;
		int x;
		for (int i = 0; i < D.size; i++)
		{
			x = D.Ds[i] + Start;
			if (x >= 56)x -= 56;
			if (Cs[Start].Ps[ID][0]->IsLegalMove(D.Ds[i]))
			{
				End[size] = x;
				size++;
			}
		}
		for (int i = 0; i < size; i++)
		{
			Cs[End[i]].Draw();
		}
	}
};

