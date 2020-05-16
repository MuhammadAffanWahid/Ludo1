#include<iostream>
#include"Team.h"
#include"Piece.h"
#include<string>
using namespace std;

class Player
{
public:
	string name;
	Team* T;
	int Rank;
	Piece Ps[4];
	int ID;
	Player() {}
	Player(int PlayerID, string name_) :ID(PlayerID), name(name_) {}
	Player(int PlayerID, string name_, Team* Team) :ID(PlayerID), name(name_), T(Team) {}
	void InitPlayer(int PlayerID, string name_,Team *t)
	{
		ID = PlayerID;
		name = name_;
		T = t;
		Rank = 0;
	}
	int CompletedPieces()
	{
		int Cp = 0;
		for (int i = 0; i < 4; i++)
		{
			if (Ps[i].state ==1)
				Cp++;
		}
		return Cp;
	}
};