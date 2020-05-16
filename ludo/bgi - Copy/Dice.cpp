#include "Dice.h"
#include<time.h>
#include "graphics.h"
#include<iostream>
#include<windows.h>

using namespace std;

int  rows = 10, cols = 10;


void Dice::RollDice(int r,int c)
{
	Ds[0] = Ds[1] = Ds[2] = 0;
	srand(time(0));
	int t = rand() % 8 + 2;
	for (int i = 0; i < t; i++)
	{
		Ds[0] = Rand() % 6 + 1;
		Beep((i+1) * 300, 500);
		UpdateDiceValues(r,c);
		delay(500);
	}
	if (Ds[0] == 6)
	{
		t = rand() % 8;
		for (int i = 0; i < t; i++)
		{
			Ds[1] = Rand() % 6 + 1;
			Beep((i + 1) * 300, 500);
			UpdateDiceValues(r, c);
			delay(500);

		}
		if (Ds[1] == 6)
		{
			t = rand() % 8;
			for (int i = 0; i < t; i++)
			{
				Ds[2] = Rand() % 6 + 1;
				Beep((i + 1) * 300, 500);
				UpdateDiceValues(r, c);
				delay(500);
			}
			if (Ds[2] == 6)
			{
				Ds[0] = Ds[1] = Ds[2] = 0;
			}
		}
		else { Ds[2] = 0; }
	}
	else { Ds[1] = Ds[2] = 0; }
	UpdateDiceValues(r, c);
}
void Dice::PrintDiceAt(int N, int ri, int ci)
{
	//int ri = 5, ci = 4;
	setcolor(GREEN);
	setfillstyle(SOLID_FILL, CYAN);
	--ci;
	bar(ci * 80, ri * 80, (ci + 1) * 80 - 1, (ri + 1) * 80 - 1);
	++ci;
	bar(ci * 80, ri * 80, (ci + 1) * 80 - 1, (ri + 1) * 80 - 1);
	++ci;
	bar(ci * 80, ri * 80, (ci + 1) * 80 - 1, (ri + 1) * 80 - 1);
	ci--;
	ri++;
	ri++;
	setfillstyle(SOLID_FILL, 1);
	bar(ci * 80, ri * 80, (ci + 1) * 80, (ri + 1) * 80);
	setbkcolor(1);
	outtextxy(ci*80 + 25,ri*80 - 20, "Roll");
}
//int Dice::RowCol2Index(int r, int c)
//{
//	int Index = 0;
//
//	if (r == 0 && c == 0)
//	{
//		Index = 0;
//	}
//	else if (r == 0 && c == rows - 1)
//	{
//		Index = cols - 1;
//	}
//	else if (c == cols - 1 && r == rows - 1)
//	{
//		Index = cols + rows - 1;
//	}
//	else if (c == 0 && r == rows - 1)
//	{
//		Index = cols + rows + cols - 1;
//	}
//	else if (c == 0)
//	{
//		Index = rows + 2 * cols + rows - r;
//	}
//	else if (c == cols - 1)
//	{
//		Index = cols + r;
//	}
//	else if (r == rows - 1)
//	{
//		Index = cols + rows + cols - c;
//	}
//	else if (r == 0)
//	{
//		Index = c;
//	}
//	return Index;
//}
void Dice::Index2RowCol(int Index)
{
	int r, c;
	if (Index <= cols - 1)
	{
		r = 0;
		c = Index;
	}
	else if (Index <= cols + rows - 1)
	{
		r = Index - cols - 1;
		c = cols;
	}
	else if (Index <= cols + rows + cols - 1)
	{
		r = rows - 1;
		c = Index - rows - cols;
	}
	else if (Index <= 2 * rows + 2 * cols - 1)
	{
		r = Index - rows - cols - cols;
		c = 0;
	}

	cout << r << " " << c << endl;

}
void Dice::UpdateDiceValues(int r,int c)
{
	char Text[50];
	settextstyle(4, 0, 3);
	setbkcolor(4);

	sprintf(Text, "%d", Ds[0]);
	outtextxy(c-80, r, Text);

	sprintf(Text, "%d", Ds[1]);
	outtextxy(c, r, Text);

	sprintf(Text, "%d", Ds[2]);
	outtextxy(c+80,r, Text);
}
int Dice::Rand()
{
	int R = (time(0) + 4 * time(0) + 3 * time(0) * time(0) - 97 * time(0) + 567 * time(0)) % 6 + 1;
	//R=R* time(0)+12345*76543;
	//R = R % 6 + 1;
	return R;
}

//int main2()
//{
//	int R = 0, C = 0;
//	initwindow(2500, 800, "Ludo");
//	PrintBoxes();
//
//	do
//	{
//		Select(R, C);
//		if ((R >= 6 && R <= 7) && (C >= 7 && C <= 8))
//			RollDice();
//	} while (true);
//
//
//
//	system("pause");
//	return 0;
//}