#pragma once
#include "Piece.h"
class rook : public Piece
{

public:
	rook(int, int, Color, Board*);
	void draw(int,int)override;

	virtual bool islegal(Board* t, int, int, int, int);
	
	
};