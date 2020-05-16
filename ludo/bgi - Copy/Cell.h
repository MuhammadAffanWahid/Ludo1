#pragma once
#include"Piece.h"
class Cell
{
public:
	Piece* Ps[4][4];
	int Size[4];
	Position P;
	void AddPeice(Piece* P, int ID)
	{
		Ps[ID][Size[ID]] = P;
		Size[ID]++;
	}
	void Draw()
	{
		bar(P.r * 80, P.c * 80, (P.r + 1) * 80 - 1, (P.c * 80) - 1);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < Size[i]; j++)
			{
				Ps[i][j]->Draw(P.r*80,P.c*80,(j*10)+20);
			}
		}
	}
	void Highlight()
	{
		setfillstyle(SOLID_FILL, GREEN);
		bar(P.r * 80, P.c * 80, (P.r + 1) * 80 - 1, (P.c * 80) - 1);
		setfillstyle(SOLID_FILL, WHITE);
	}
};

