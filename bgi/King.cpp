#include "King.h"

#include <iostream>
using namespace std;



King::King(int _r, int _c, Color _C, Board* _b) :Piece(_r, _c, _C, _b)
{
	t = 'k'; promo = 0;
}
void King::draw(int r, int c)
{
	if (color == BLUE)
	{
		setfillstyle(1, BLUE);
		readimagefile("Wking.gif", c - 25, r - 25, c + 25, r + 25);
	}
	if (color == BLACK)
	{
		
		readimagefile("Bking.gif", c - 25, r - 25, c + 25, r + 25);
	}
}
bool King::islegal(Board*t, int sri, int sci, int dri, int dci)
{
	int R = abs(dri - sri); int C =abs( dci - sci);
	return (R == 1 && C==0 && IsVertiPathClear(t,sci,sri,dci,dri))||(R == 0 && C == 1 && IsHorizonPathClear(t, sci, sri, dci, dri))||(R==1 && C==1 && IsDiagPathClear(t, sci, sri, dci, dri));
}
