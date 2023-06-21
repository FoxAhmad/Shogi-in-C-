#pragma once
#include "Piece.h"
class gold : public Piece
{

public:
	gold(int, int, Color, Board*);
	void draw(int,int)override;
	virtual bool islegal(Board* t, int, int, int, int);

};