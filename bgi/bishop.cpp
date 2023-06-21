#include "bishop.h"

#include <iostream>
using namespace std;



bishop::bishop(int _r, int _c, Color _C, Board* _b) :Piece(_r, _c, _C, _b)
{
	t = 'b'; promo = 0;
}
void bishop::draw(int r,int c)
{
	if (this->getpromo() == false)
	{
		if (color == BLUE)
		{
			setfillstyle(1, BLUE);
			readimagefile("Wbishop.gif", c - 25, r - 25, c + 25, r + 25);
		}
		if (color == BLACK)
		{

			readimagefile("Bbishop.gif", c - 20, r - 20, c + 20, r + 20);
		}
	}
	else if (this->getpromo() == true)
	{
		if (color == BLUE)
		{
			setfillstyle(1, BLUE);
			readimagefile("Wpromobishop.gif", c - 30, r - 25, c + 30, r + 25);
		}
		if (color == BLACK)
		{

			readimagefile("Bpromobishop.gif", c - 30, r - 25, c + 30, r + 25);
		}
	}
}
bool bishop::islegal(Board*t ,int sri, int sci, int dri, int dci)
{
	if(this->getpromo()==false)
	return IsDiagPath(sci, sri, dci, dri) && IsDiagPathClear(t,sci,sri,dci,dri);
	
	else if (this->getpromo() == true)
	{
		int R = abs(dri - sri); int C = abs(dci - sci);
		return IsDiagPath(sci, sri, dci, dri) && IsDiagPathClear(t, sci, sri, dci, dri)||(R==1&&C==0) ||(R==0&& C==1);
	}
}
