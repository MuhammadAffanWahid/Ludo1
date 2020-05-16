#pragma once
#include"Dice.h"
#include"Board.h"
#include"Player.h"
#include"Position.h"
#include"Piece.h"
#include<iostream>
using namespace std;

class Ludo
{
private:
	Player* Pl;
	Board B;
	Position SP;
	Position EP;
	int NOP;
	int NOT;
	int Turn;
	bool TeamMode;
	Dice D;
	int PlayersCompleted = 0;

public:
	void Select(int& R, int& C);
	void Init();
	void InitPeices();
	void InitRed();
	void InitPurple();
	void InitCyan();
	void InitBlue();
	void InitYellow();
	void InitGreen();
	void InitAll();
	void Play();
	void TurnChange(int &turn);
	bool GameEnd();
	void DisplayResults();
	void SelectPiece(int& ri, int& ci, Piece* MyBoard[100][100]);
	void SelectDestination(int& ri, int& ci, Piece* MyBoard[100][100]);
	bool IsValidSelection(Position Start, Position End, Piece* MyBoard[100][100]);
	bool IsValidDestination(Position Start, Position End, Piece* MyBoard[100][100]);
	void DisplayResult();
	void CompletedAll(Player);
};

