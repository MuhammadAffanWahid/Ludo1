#include "graphics.h"
#include <iostream>
#include"Dice.h"
#include"Ludo.h"
using namespace std;
void Select(int& R, int& C)
{
	do
	{

	} while (!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, R, C);
	Beep(1000, 500);
	C = C / 80;
	R = R / 80;
}
int main()
{
	Ludo L;
	L.Play();
	//int r, c;
	//initwindow(1900, 1000, "Ludo");
	//setfillstyle(SOLID_FILL, YELLOW);
	//setcolor(BLACK);
	//setbkcolor(YELLOW);
	//bar(0, 0, 79, 79);
	//bar(80, 0, 159, 79);
	//bar(160, 0, 239, 79);
	//outtextxy(15, 30, "2 Player");
	//outtextxy(15 + 80, 30, "4 Player");
	//outtextxy(15 + 160, 30, "6 Player");
	//do
	//{
	//	Select(r, c);
	//} while (c != 0 || r >= 3);
	//setbkcolor(BLACK);
	//cleardevice();
	//cout << "r";
	//initwindow(1900, 1000, "Ludo");
	//Dice D;
	//D.PrintDiceAt(1, 7, 7);
	//D.RollDice(7*80 + 30, 7*80 + 30);
	////D.PrintDiceAt(6, 50, 50);
	//delay(1000000);
	//for (int ri = 0; ri < 20; ri++)
	//{
	//	for (int ci = 0; ci < 10; ci++)
	//	{
	//		if (ri == 0 || ri == 19 || ci == 0 || ci == 9)
	//			bar(ri * 80, ci * 80, (ri + 1) * 80 - 1, (ci + 1) * 80 - 1);
	//	}
	//}
	//setfillstyle(SOLID_FILL, 4);	//Red
	//bar(80, 80, 239, 239);
	//setfillstyle(SOLID_FILL, 1);    //Blue
	//bar(80, 560, 239, 719);
	//setfillstyle(SOLID_FILL, 2);	//	Green
	//bar(17 * 80, 560, 19 * 80-1, 719);

	//setfillstyle(SOLID_FILL, 3);     //cyan
	//bar(1360, 80, 1519, 239);
	//setfillstyle(SOLID_FILL, 5);	//purple
	//bar(640, 80, 799, 239);
	//setfillstyle(SOLID_FILL, 6);		// yelllow
	//bar(640, 560, 799, 719);

	////Homes
	//setfillstyle(SOLID_FILL, 4);	//Red stay
	//bar(80, 0, 159, 79);
	//setfillstyle(SOLID_FILL, 4);
	//bar(10, 10, 70,70);
	//setfillstyle(SOLID_FILL, 1);	//Blue stay
	//bar(160, 9*80, 239,799);
	//setfillstyle(SOLID_FILL, 1);
	//bar(250, 730, 309, 789);

	//setfillstyle(SOLID_FILL, 2);	//	Green //Stay
	//bar(18*80, 800, 19*80-1, 719);
	//setfillstyle(SOLID_FILL, 2);
	//bar(19 * 80 + 10, 9 * 80 + 10, 20 * 80 - 10, 10 * 80 - 10);
	//setfillstyle(SOLID_FILL, 3);	//cyan Stay
	//bar(17*80, 0, 18*80 - 1, 79);
	//setfillstyle(SOLID_FILL, 3);
	//bar(16*80+10, 10, 17*80-10, 70);

	//setfillstyle(SOLID_FILL, 5);	//Purple Stay
	//bar(640, 0, 719, 79);
	//setfillstyle(SOLID_FILL, 5);
	//bar(570, 10, 630, 70);

	//setfillstyle(SOLID_FILL, 6);	//Yellow Stop
	//bar(720, 800, 799, 719);
	//setfillstyle(SOLID_FILL, 6);
	//bar(10*80 + 10, 9*80+10, 11*80-10, 10*80-10);
	delay(10000000000);
}