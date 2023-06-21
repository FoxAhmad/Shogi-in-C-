#pragma once
#include "graphics.h"
#include "Board.h"
#include "Header.h"
class Board;
class Piece
{
protected:
	
	Color color;
	bool promo;
	
	bool IsHorizonPath(int sci, int sri, int dci, int dri)
	{
		return (sri == dri);
	}
	bool IsVertiPath(int sci, int sri, int dci, int dri)
	{
		return (sci == dci);
	}
	bool IsDiagPath(int sci, int sri, int dci, int dri)
	{
		int Cr = dri - sri;
		if (Cr < 0)
		{
			Cr = Cr * (-1);
		}
		int Cc = dci - sci;
		if (Cc < 0)
		{
			Cc = Cc * (-1);
		}
		return (Cr == Cc);

	}

	bool IsHorizonPathClear(Board* B, int sci, int sri, int dci, int dri)
	{
		int cs = 0, ce = 0;
		if (dci > sci)
		{
			cs = sci + 1;
			ce = dci - 1;
		}
		if (dci < sci)
		{
			ce = sci - 1;
			cs = dci + 1;
		}
		for (int i = cs; i <= ce; i++)
		{
			if (B->getpiece(dri , i ) != nullptr)
			{
				return false;
			}

		}
		return true;
	}
	bool IsVertiPathClear(Board* B, int sci, int sri, int dci, int dri)
	{
		int rs = 0, re = 0;
		if (dri > sri)
		{
			rs = sri + 1;
			re = dri - 1;
		}
		if (dri < sri)
		{
			re = sri - 1;
			rs = dri + 1;
		}
		for (int i = rs; i <= re; i++)
		{
			if (B->getpiece(i, dci) != nullptr)
			{
				return false;
			}

		}
		return true;
	}
	bool IsDiagPathClear(Board* B, int sci, int sri, int dci, int dri)
	{
		int R = abs(dri - sri);

		for (int i = 1; i < R; i++)
		{
			if ((dri < sri) && (dci < sci))
			{
				if (B->getpiece(sri - i,sci - i) != nullptr)
				{
					return false;
				}

			}
			else if ((dri < sri) && (dci > sci))
			{
				if (B->getpiece(sri - i, sci + i) != nullptr)
				{
					return false;
				}

			}
			else if ((dri > sri) && (dci < sci))
			{
				if (B->getpiece(sri + i, sci - i) != nullptr)
				{
					return false;
				}

			}
			else if ((dri > sri) && (dci > sci))
			{
				if (B->getpiece(sri + i, sci + i) != nullptr)
				{
					return false;
				}

			}

		}
		return true;
	}
public:
	Piece(int, int, Color,Board*);
	 char t;
	int ri, ci;
	void move(int , int);
	virtual bool islegal(Board* t, int, int, int, int)=0;
	virtual void draw(int ,int)=0;
	Board* b;
	Color getclr();
	void setclr(Color);
	  bool getpromo();
	 void setpromo(bool);
	 int count=0;

};

