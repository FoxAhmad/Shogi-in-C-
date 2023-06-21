#pragma once
#include "Piece.h"
class King: public Piece
{

public:
	King(int, int, Color, Board*);
	void draw(int,int)override;
	virtual bool islegal(Board* t, int, int, int, int);
	
};