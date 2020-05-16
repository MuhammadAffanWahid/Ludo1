#include "Ludo.h"
#include "team.h"
#include "Position.h"
#include <iostream>
#include <windows.h>
#include <math.h>

//red=0 purple=4 cyan=1 blue=2 yellow/golden=5 green=3

void Ludo::Init()
{
     bool Solo = false;
     TeamMode = false;
     initwindow(1900, 1000, "Ludo");
     setfillstyle(SOLID_FILL, GREEN);
     bar(0, 0, 159, 79);
     bar(160, 0, 319, 79);
     outtextxy(30, 30, "SOLO MODE");
     outtextxy(190, 30, "TEAM MODE");
     int r, c;
     do
     {
         Select(r, c);
     } while (c != 0 || r >= 4);
     cleardevice();
     if (r < 2)Solo = true;
     if (Solo)
     {
        bar(0, 0, 79, 79);
        bar(80, 0, 159, 79);
        bar(160, 0, 239, 79);
        outtextxy(15, 30, "2 Player");
        outtextxy(15 + 80, 30, "4 Player");
        outtextxy(15 + 160, 30, "6 Player");
        do
        {
            Select(r, c);
        } while (c != 0 || r >= 3);
        setbkcolor(BLACK);
        cleardevice();
        NOP = 2 * (r + 1);
        NOT = NOP;
    }
    else
    {
        NOP = 6;
        NOT = 2;
        TeamMode = true;
    }
    Pl = new Player[NOP];
    if (TeamMode)
    {
        Team T1(0,3,Pl);
        Team T2(1, 3, Pl + 3);
        for (int i = 0; i < 6; i++)
        {
            string N = "Player ";
            char s = '0';
            s += i;
            N += s;
            if (i < 3)
                Pl[i].InitPlayer(0, N, &T1);
            else
                Pl[i].InitPlayer(0, N, &T2);

        }
    }
    else
    {
        for (int i = 0; i < NOP; i++)
        {
            string N = "Player ";
            char s = '0';
            s += i;
            N += s;
            Pl[i].InitPlayer(0, N, &Team(i,1,&Pl[i]));
        }
    }
}
void Ludo::InitPeices()
{
    if (TeamMode||NOP==6)
    {
        InitAll();
    }
    else
    {
        switch (NOP)
        {
        case 2:
            InitRed();
            InitCyan();
            break;
        case 4:
            InitRed();
            InitCyan();
            InitBlue();
            InitGreen();
            break;
        }
    }
}
void Ludo::InitAll()
{
    InitRed();
    InitPurple();
    InitCyan();
    InitBlue();
    InitYellow ();
    InitGreen();

}
//20+(id*10)
void Ludo::InitRed() 
{
    Pl[0].Ps[0].InitPiece(&Pl[0], 0, Position(1, 1), Position(0, 20), 1, 0, 20);
    Pl[0].Ps[1].InitPiece(&Pl[0], 0, Position(1, 2), Position(0, 21), 1, 0, 20);
    Pl[0].Ps[2].InitPiece(&Pl[0], 0, Position(2, 1), Position(0, 22), 1, 0, 20);
    Pl[0].Ps[3].InitPiece(&Pl[0], 0, Position(2, 2), Position(0, 23), 1, 0, 20);
}
void Ludo::InitPurple()
{
    Pl[4].Ps[0].InitPiece(&Pl[4], 4, Position(1, 1), Position(0, 20), 8,7, 60);
    Pl[4].Ps[1].InitPiece(&Pl[4], 4, Position(1, 2), Position(0, 21), 8, 7, 60);
    Pl[4].Ps[2].InitPiece(&Pl[4], 4, Position(2, 1), Position(0, 22), 8, 7, 60);
    Pl[4].Ps[3].InitPiece(&Pl[4], 4, Position(2, 2), Position(0, 23), 8, 7, 60);
}
void Ludo::InitCyan()
{
    Pl[1].Ps[0].InitPiece(&Pl[2], 1, Position(1, 1), Position(0, 20), 17, 16, 30);
    Pl[1].Ps[1].InitPiece(&Pl[2], 1, Position(1, 2), Position(0, 21), 17, 16, 30);
    Pl[1].Ps[2].InitPiece(&Pl[2], 1, Position(2, 1), Position(0, 22), 17, 16, 30);
    Pl[1].Ps[3].InitPiece(&Pl[2], 1, Position(2, 2), Position(0, 23), 17, 16, 30);
}
void Ludo::InitBlue()
{
    Pl[2].Ps[3].InitPiece(&Pl[3],2, Position(2, 2), Position(0, 23), 45, 44, 40);   
    Pl[2].Ps[0].InitPiece(&Pl[3],2, Position(1, 1), Position(0, 20), 45, 44, 40);   
    Pl[2].Ps[1].InitPiece(&Pl[3],2, Position(1, 2), Position(0, 21), 45, 44, 40);   
    Pl[2].Ps[2].InitPiece(&Pl[3],2, Position(2, 1), Position(0, 22), 45, 44, 40);   
}
void Ludo::InitYellow()
{
    Pl[5].Ps[0].InitPiece(&Pl[5], 5, Position(1, 1), Position(0, 20), 38, 37, 70);
    Pl[5].Ps[1].InitPiece(&Pl[5], 5, Position(1, 2), Position(0, 21), 38, 37, 70);
    Pl[5].Ps[2].InitPiece(&Pl[5], 5, Position(2, 1), Position(0, 22), 38, 37, 70);
    Pl[5].Ps[3].InitPiece(&Pl[5], 5, Position(2, 2), Position(0, 23), 38, 37, 70);
}
void Ludo::InitGreen()
{
    Pl[3].Ps[0].InitPiece(&Pl[3], 3, Position(1, 1), Position(0, 20), 29, 28, 50);
    Pl[3].Ps[1].InitPiece(&Pl[3], 3, Position(1, 2), Position(0, 21), 29, 28, 50);
    Pl[3].Ps[2].InitPiece(&Pl[3], 3, Position(2, 1), Position(0, 22), 29, 28, 50);
    Pl[3].Ps[3].InitPiece(&Pl[3], 3, Position(2, 2), Position(0, 23), 29, 28, 50);
}
bool Ludo::GameEnd()
{
    int Count=0;
    for(int i=0;i<NOP;i++)
        {
        if (Pl[i].Rank == 0)
            Count++;
		}
    if (Count > 1)return false;
    return true;
}

void Ludo::CompletedAll(Player Pl)
{
  //  for (int i=0;i<NOP;i++)
    //{
    int count = 0;
        for (int x = 0; x < 4; x++)
        {
            if (Pl.Ps[x].state == -1)
                count++;
        }
        if (count == 4)
        {
            PlayersCompleted++;
            Pl.Rank = PlayersCompleted;
        }
                                         
    //}
}
void Ludo::TurnChange(int &turn)
{
    turn = (turn + 1) % NOP;
}
void Ludo::SelectPiece(int& ri, int& ci, Piece* MyBoard[100][100])
{
    int tempr, tempc;
   
    ri = tempr;
    ci = tempc;
}
void Ludo::SelectDestination(int& ri, int& ci, Piece* MyBoard[100][100])
{
    int tempr, tempc;
   
    ri = tempr;
    ci = tempc;
}
void Ludo::Select(int& R, int& C)
{
    do
    {

    } while (!ismouseclick(WM_LBUTTONDOWN));
    Beep(532, 200);
    getmouseclick(WM_LBUTTONDOWN, R, C);
    C = C / 80;
    R = R / 80;
}
bool Ludo::IsValidSelection(Position Start, Position End, Piece* MyBoard[100][100])
{
    if (MyBoard[End.r][End.c] == nullptr)
        return false;

    if (MyBoard[End.r][End.c]->Token==Turn)
        return true;

    return false;
}
bool Ludo::IsValidDestination(Position Start, Position End, Piece* MyBoard[100][100])
{

    return 1;
}
void Ludo::DisplayResult() {}
void Ludo::Play()
{
    Init();
    InitPeices();
    B.Display();      
    D.PrintDiceAt(1, 4, 9);
    D.RollDice(4*80+30,9*80+30);
    while (!GameEnd())
    {
        D.RollDice(7 * 80 + 30, 7 * 80 + 30);
        /*do
        {
            do {
                std::cout << "Select Piece";
                SelectPiece();
            } while (IsValidSelection() == false);
            B.Highlight(SP, D);
            cout << "Select Destination";
            SelectDestination();
            if (IsValidDestination() == false)
            {
                cout << "Invalid Move";
            }
            B.UnHighlight(SP, D);
        } while (B.Ps[SP.r][SP.c]->IsLegalMove(EP, D));
        B.Move(SP, EP);
        TurnChange(cColor);*/
        delay(1000000000);
    }
    DisplayResult();
    return;


}
