#pragma once
#include "Piece.h"
class knight : public Piece
{

public:
	knight(int, int, Color, Board*);
	void draw(int,int)override;
	virtual bool islegal(Board* t, int, int, int, int);
	
};