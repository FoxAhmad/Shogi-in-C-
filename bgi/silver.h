#pragma once
#include "Piece.h"
class silver : public Piece
{

public:
	silver(int, int, Color, Board*);
	void draw(int,int)override;
	virtual bool islegal(Board* t, int, int, int, int);
	
};