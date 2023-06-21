#include "lance.h"

#include <iostream>
using namespace std;



lance::lance(int _r, int _c, Color _C, Board* _b) :Piece(_r, _c, _C, _b)
{
	t = 'l'; promo = 0;
}
void lance::draw(int r, int c)
{
	if (getpromo() == false)
	{
		if (color == BLUE)
		{
			setcolor(BLUE);
			readimagefile("lanceW.gif", c - 25, r - 25, c + 25, r + 25);
		}
		if (color == BLACK)
		{

			readimagefile("lanceB.gif", c - 25, r - 25, c + 25, r + 25);
		}
	}
	else
	{
		if (color == BLUE)
		{
			setcolor(BLUE);
			readimagefile("Wpromolance.gif", c - 20, r - 25, c + 20, r + 25);
		}
		if (color == BLACK)
		{

			readimagefile("Bpromolance.gif", c - 20, r - 25, c + 20, r + 25);
		}
	}
}
bool lance::islegal(Board*t,int sri, int sci, int dri, int dci)
{
	if (getpromo() == false)
	{
		int R = dri - sri; int C = dci - sci;
		if (getclr() == BLUE)
			return (R >= 1) && C == 0 && IsVertiPathClear(t, sci, sri, dci, dri);

		return (R <= -1) && C == 0 && IsVertiPathClear(t, sci, sri, dci, dri);
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
