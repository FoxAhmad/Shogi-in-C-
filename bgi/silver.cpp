#include "silver.h"

#include <iostream>
using namespace std;



silver::silver(int _r, int _c, Color _C, Board* _b) :Piece(_r, _c, _C, _b)
{
	t = 's'; promo = 0;
}
void silver::draw(int r, int c)
{
	if (getpromo() == false)
	{
		if (color == BLUE)
		{
			setcolor(BLUE);
			readimagefile("silvergenW.gif", c - 25, r - 25, c + 25, r + 25);
		}
		if (color == BLACK)
		{

			readimagefile("silvergenB.gif", c - 25, r - 25, c + 25, r + 25);
		}
	}
	else
	{
		if (color == BLUE)
		{
			setcolor(BLUE);
			readimagefile("Wpromosilver.gif", c - 25, r - 25, c + 25, r + 25);
		}
		if (color == BLACK)
		{

			readimagefile("Bpromosilver.gif", c - 25, r - 25, c + 25, r + 25);
		}
	}
}
bool silver::islegal(Board* t, int sri, int sci, int dri, int dci)
{
	if (getpromo() == false)
	{
		int R = (dri - sri);
		int C = abs(dci - sci);
		if (this->getclr() == BLACK)
		{
			return (R == -1 && C == 0) || (IsDiagPath(sci, sri, dci, dri) && IsDiagPathClear(t, sci, sri, dci, dri) && ((R == 1 || R == -1) && C == 1));
		}
		if (this->getclr() == BLUE)
		{
			return (R == 1 && C == 0) || (IsDiagPath(sci, sri, dci, dri) && IsDiagPathClear(t, sci, sri, dci, dri) && ((R == 1 || R == -1) && C == 1));
		}
	}
	else
	{
		int R = dri - sri; int C = dci - sci;
		if (getclr() == BLACK)
			return ((R == -1 && abs(C) == 1) || (abs(C) == 1 && R == 0 && IsHorizonPathClear(t, sci, sri, dci, dri)) || (abs(R) == 1 && C == 0 && IsVertiPathClear(t, sci, sri, dci, dri)));
		else
			return ((R == 1 && abs(C) == 1) || (abs(C) == 1 && R == 0 && IsHorizonPathClear(t, sci, sri, dci, dri)) || (abs(R) == 1 && C == 0 && IsVertiPathClear(t, sci, sri, dci, dri)));

	}
	
}
