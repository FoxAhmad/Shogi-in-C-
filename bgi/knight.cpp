#include "knight.h"

#include <iostream>
using namespace std;



knight::knight(int _r, int _c, Color _C, Board* _b) :Piece(_r, _c, _C, _b)
{
	t = 'h'; promo = 0;
}
void knight::draw(int r, int c)
{
	if (getpromo() == false)
	{
		if (color == BLUE)
		{
			setfillstyle(1, BLUE);
			readimagefile("Whorse.gif", c - 25, r - 25, c + 25, r + 25);
		}
		if (color == BLACK)
		{

			readimagefile("Bhorse.gif", c - 25, r - 25, c + 25, r + 25);
		}
	}
	else
	{
		if (color == BLUE)
		{
			setfillstyle(1, BLUE);
			readimagefile("Wpromoknight.gif", c - 27, r - 30, c + 27, r + 30);
		}
		if (color == BLACK)
		{

			readimagefile("Bpromoknight.gif", c - 27, r - 30, c + 27, r + 30);
		}
	}
}
bool knight::islegal( Board*t,int sri, int sci, int dri, int dci)
{
	if (getpromo() == false)
	{
		int R = dri - sri; int C = abs(dci - sci);
		int d = (getclr() == BLUE) ? 2 : -2;
		return (R == d && C == 1);
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
