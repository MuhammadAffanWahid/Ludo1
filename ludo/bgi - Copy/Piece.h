#pragma once
#include"Position.h"
#include"graphics.h"
class Player;
class Piece
{
public:	
	Player* Pl;
	int Token;
	int state;
	int BoardPosition;
	int Home;
	int End;
	int yShift;
	/*
		Red=4;
		Purple=9;
		Cyan=3;
		Blue=1;
		Yellow=14;
		Green=10;
	*/
	Position HomePosition;
	Position EndPosition;
	Piece(Player* P, int token,  Position Homeposition,int home,int end, int yshift = 0) :Pl(P), Token(token)
		, yShift(yshift), HomePosition(Homeposition),Home(home),End(end)
	{
		BoardPosition = -1;
		state = -1;
	}
	Piece() {}
	void InitPiece(Player* P, int token, Position Homeposition,Position Endposition, int home, int end, int yshift)
	{
		Pl = P;
		Token = token;
		yShift = yshift;
		HomePosition = Homeposition;
		EndPosition = Endposition;
		Home = home;
		End = end;
	}
	void Draw(int ri, int ci, int xShift,int size = 10)
	{
		setfillstyle(SOLID_FILL, Token);
		setcolor(BLACK);
		circle(ci + xShift, ri + yShift, size);
	}
	void Draw()
	{
		setfillstyle(SOLID_FILL, Token);
		setcolor(BLACK);
		if (state == 1)
			circle(HomePosition.c * 80 + 40, HomePosition.r * 80 + 40, 10);
		if (state == -1)
			circle(EndPosition.c * 80 + 40, EndPosition.r * 80 + 40, 10);
	}
	bool IsLegalMove(int Dice)
	{
		int n = BoardPosition + Dice;
		if (n > 55)n -= 56;
		if (state == 1) return false;
		if (state == -1 && Dice != 6) return false;
		int x;
		for (int i = 0; i < Dice; i++)
		{
			x = n - i;
			if (x < 0)x = 55;
			if (x == Home) return false;
		}
		return true;
	}
	void Move(int Dice)
	{
		if (state == -1 && Dice == 6)
		{
			BoardPosition = Home;
			return;
		}
		if (BoardPosition + Dice == End)
		{
			BoardPosition = -1;
			state = 1;
			return;
		}
		BoardPosition += Dice;
		

	}
};

