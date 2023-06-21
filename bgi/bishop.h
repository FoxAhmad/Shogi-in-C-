#pragma once
#include "Piece.h"
class bishop : public Piece
{

public:
	bishop(int, int, Color, Board*);
	void draw(int,int)override;
	virtual bool islegal(Board* t, int, int, int, int);

};