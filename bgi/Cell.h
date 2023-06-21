#pragma once
#include"Piece.h"

class Cell
{

	
	
	

public:
	Cell(int ,int  , Piece* );

	Piece* getpc();
	void setpc(Piece*);
	void draw(int ,int);
	int l = 65, w = 65; int r, c;
	Piece* Pc;
};

