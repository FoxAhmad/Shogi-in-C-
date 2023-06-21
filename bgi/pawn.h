#pragma once
#include "Piece.h"
class pawn : public Piece
{
protected:
	
public:
	pawn(int, int, Color, Board*);
	virtual bool islegal(Board* t, int,int,int,int);
	void draw(int,int)override;
	
	

};
