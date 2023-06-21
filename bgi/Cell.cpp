#include "Cell.h"
#include<iostream>
#include"Piece.h"
#include "bishop.h"
#include "rook.h"
#include "silver.h"
#include "gold.h"
#include "king.h"
#include "lance.h"
#include"knight.h"
#include "pawn.h"
#include "graphics.h"
using namespace std;


Cell::Cell(int ri , int ci  , Piece* P )
{
	r = ri;
	c = ci;
	Pc = P;
	
}
void Cell::draw(int _r,int _c )
{
	setcolor(RGB(0, 0, 0));
	
	
		setfillstyle(1, RGB(253, 190, 19));
	
	
	
	bar3d(_c * w+30, _r * l+30, c * w + w+30, r * l + l+30, 0, 0);
	if(Pc!=nullptr)
		Pc->draw(r * l + 32+30, c * w + 32+30);
		
}

void Cell::setpc(Piece* p)
{
	//delete Pc;
	if (p != nullptr)
	{
		switch (p->t)
		{
		case 'p':
			this->Pc = new pawn(p->ri, p->ci, p->getclr(), p->b);
			this->Pc->setpromo(p->getpromo());
			this->Pc->count =(p->count);
			break;
		case 'b':
			this->Pc = new bishop(p->ri, p->ci, p->getclr(), p->b);
			this->Pc->setpromo(p->getpromo());
			this->Pc->count = (p->count);
			break;
		case 'k':
			this->Pc = new King(p->ri, p->ci, p->getclr(), p->b);
			this->Pc->setpromo(p->getpromo());
			this->Pc->count = (p->count);
			break;
		case 'h':
			this->Pc = new knight(p->ri, p->ci, p->getclr(), p->b);
			this->Pc->setpromo(p->getpromo());
			this->Pc->count = (p->count);
			break;
		case 'l':
			this->Pc = new lance(p->ri, p->ci, p->getclr(), p->b);
			this->Pc->setpromo(p->getpromo());
			this->Pc->count = (p->count);
			break;
		case 's':
			this->Pc = new silver(p->ri, p->ci, p->getclr(), p->b);
			this->Pc->setpromo(p->getpromo());
			this->Pc->count = (p->count);
			break;
		case 'g':
			this->Pc = new gold(p->ri, p->ci, p->getclr(), p->b);
			this->Pc->setpromo(p->getpromo());
			this->Pc->count = (p->count);
			break;
		case 'r':
			this->Pc = new rook(p->ri, p->ci, p->getclr(), p->b);
			this->Pc->setpromo(p->getpromo());
			this->Pc->count = (p->count);
			break;
		}
	}
	else
	{
		Pc = nullptr;
	}
}
Piece* Cell::getpc()
{
	return this->Pc;
}