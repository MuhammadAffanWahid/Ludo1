#pragma once
class Dice
{
private:
	void Index2RowCol(int);
	void RowCol2Index(int, int);
	void UpdateDiceValues(int r,int c);
	int Rand();
	
public:
	int Ds[3];
	int size;
	void RollDice(int r,int c);
	void PrintDiceAt(int N, int ri, int ci);
};
