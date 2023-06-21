#include "Piece.h"
#include<iostream>
using namespace std;
Piece::Piece(int _r, int _c, Color _C ,Board* _b)
{
	ri = _r;
	ci = _c;
	color = _C;
	b = _b;
}

void Piece::move(int _r , int _c)
{
	this->ri = _r;
	this->ci = _c;
}

Color Piece::getclr()
{
	return color;
}
void Piece::setclr(Color m)
{
	color = m;
}
bool Piece::getpromo()
{
	return promo;
}
void Piece::setpromo(bool b)
{
	promo = b;
}

