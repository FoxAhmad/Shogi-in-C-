#include "rook.h"

#include <iostream>
using namespace std;



rook::rook(int _r, int _c, Color _C, Board* _b) :Piece(_r, _c, _C, _b)
{
	t = 'r'; promo = 0;
}
void rook::draw(int r, int c)
{
	if (getpromo() == false)
	{
		if (color == BLUE)
		{
			setfillstyle(1, BLUE);
			readimagefile("Wrook.gif", c - 17, r - 22, c + 17, r + 22);
		}
		if (color == BLACK)
		{

			readimagefile("Brook.gif", c - 17, r - 22, c + 17, r + 22);
		}
	}
	else
	{
		if (color == BLUE)
		{
			setfillstyle(1, BLUE);
			readimagefile("Wpromorook.gif", c - 25, r - 25, c + 25, r + 25);
		}
		if (color == BLACK)
		{

			readimagefile("Bpromorook.gif", c - 25, r - 25, c + 25, r + 25);
		}
	}
}
bool rook::islegal(Board* t, int sri, int sci, int dri, int dci)
{
	if(getpromo()==false)
	return (IsHorizonPath(sci,sri,dci,dri)&&IsHorizonPathClear(t,sci,sri,dci,dri))|| (IsVertiPath(sci, sri, dci, dri) && IsVertiPathClear(t, sci, sri, dci, dri));
	else
	{
		int R = abs(dri - sri); int C = abs(dci - sci);
		return(IsHorizonPath(sci, sri, dci, dri) && IsHorizonPathClear(t, sci, sri, dci, dri)) || (IsVertiPath(sci, sri, dci, dri) && IsVertiPathClear(t, sci, sri, dci, dri)) || (R == 1 && C == 0 && IsVertiPathClear(t, sci, sri, dci, dri)) || (R == 0 && C == 1 && IsHorizonPathClear(t, sci, sri, dci, dri)) || (R == 1 && C == 1 && IsDiagPathClear(t, sci, sri, dci, dri));
	}
}
