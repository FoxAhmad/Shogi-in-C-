#include "gold.h"

#include <iostream>
using namespace std;



gold::gold(int _r, int _c, Color _C, Board* _b) :Piece(_r, _c, _C, _b)
{
	t = 'g'; promo = 0;
}
void gold::draw(int r, int c)
{
	if(color == BLUE)
	{
		setcolor(BLUE);
		readimagefile("goldgeneralW.gif", c - 25, r - 25, c + 25, r + 25);
	}
	if (color == BLACK)
	{

		readimagefile("goldgeneralB.gif", c - 25, r - 25, c + 25, r + 25);
	}
}
bool gold::islegal(Board*t, int sri, int sci, int dri, int dci)
{
	int R = dri - sri; int C = dci - sci;
	if (getclr() == BLACK)
	return ( (R==-1 && abs(C)==1)|| (abs(C) == 1&& R == 0 && IsHorizonPathClear(t, sci, sri, dci, dri)) || (abs(R) == 1&& C==0 && IsVertiPathClear(t, sci, sri, dci, dri)));
	else
	 return ((R == 1 && abs(C) == 1) || (abs(C) == 1 && R==0 && IsHorizonPathClear(t, sci, sri, dci, dri)) || (abs(R) == 1&&C==0 && IsVertiPathClear(t, sci, sri, dci, dri)));

}
