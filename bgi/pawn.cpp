#include "pawn.h"
#include "Piece.h"
#include <iostream>
using namespace std;



pawn::pawn(int _r, int _c, Color _C, Board* _b):Piece(_r , _c , _C,_b)
{
	t = 'p'; promo = 0;
}
void pawn::draw(int r, int c)
{
	if (getpromo() == false)
	{
		if (color == BLUE)
		{
			setcolor(BLUE);
			readimagefile("Wpawn.gif", c - 25, r - 25, c + 25, r + 25);
		}
		if (color == BLACK)
		{

			readimagefile("Bpawn.gif", c - 14, r - 20, c + 14, r + 20);
		}
	}
	else if (getpromo() == true)
	{
		if (color == BLUE)
		{
			setcolor(BLUE);
			readimagefile("Wpromopawn.gif", c - 17, r - 23, c + 17, r + 23);
		}
		if (color == BLACK)
		{

			readimagefile("Bpromopawn.gif", c - 17, r - 23, c + 17, r + 23);
		}
	}
}

bool pawn::islegal(Board*t,int sri, int sci, int dri, int dci)
{
	if (getpromo() == false)
	{
		int R = dri - sri;
		int C = abs(dci - sci);
		if (this->getclr() == BLACK)
		{
			return (R == -1 && C == 0);
		}
		if (this->getclr() == BLUE)
		{
			return (R == 1 && C == 0);
		}
	}
	else if (getpromo() == true)
	{
		int R = dri - sri; int C = dci - sci;
		if (getclr() == BLACK)
			return ((R == -1 && abs(C) == 1) || (abs(C) == 1 && R == 0 && IsHorizonPathClear(t, sci, sri, dci, dri)) || (abs(R) == 1 && C == 0 && IsVertiPathClear(t, sci, sri, dci, dri)));
		else
			return ((R == 1 && abs(C) == 1) || (abs(C) == 1 && R == 0 && IsHorizonPathClear(t, sci, sri, dci, dri)) || (abs(R) == 1 && C == 0 && IsVertiPathClear(t, sci, sri, dci, dri)));

	}
}

