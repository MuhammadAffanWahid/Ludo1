#pragma once
#include<string>
using namespace std;
class Player;
class Team
{
public:
	int ID;
	Player* Ps;
	int NOP;
	Team(int id, int Nop, Player* ps) :ID(id), NOP(Nop), Ps(ps) {}
};

