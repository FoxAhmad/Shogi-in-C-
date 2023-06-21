#pragma once
#include "Piece.h"
class lance : public Piece
{

public:
	lance(int, int, Color, Board*);
	void draw(int,int)override; virtual bool islegal(Board* t, int, int, int, int);
	
	
};