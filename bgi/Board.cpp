#include "Board.h"
#include "Piece.h"
#include "pawn.h"
#include "King.h"
#include "lance.h"
#include "knight.h"
#include "silver.h"
#include "gold.h"
#include "bishop.h"
#include "rook.h"
#include "Cell.h"
#include <iostream>

using namespace std;






Board::Board()
{
		
		
	}

Board::Board(ifstream& rdr,bool &b)
{
	char n[9][18];
	bool wannabreak=false;
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 18; x++)
		{
			
			if (rdr.peek() == std::ifstream::traits_type::eof())
			{
				wannabreak = true;
				break;
			}
			rdr >> n[y][x];
		}
		if (wannabreak == true)
			break;
	}
	if (wannabreak != true)
	{
		this->Cs = new Cell * *[9];
		for (int y = 0; y < 9; y++)
		{
			Cs[y] = new Cell * [9];
			for (int z = 0, x = 0; z < 18; z += 2, x++)
			{
				switch (n[y][z])
				{
				case 'l':
					this->Cs[y][x] = new Cell(y, x, new lance(y, x, BLUE, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'h':
					this->Cs[y][x] = new Cell(y, x, new knight(y, x, BLUE, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'g':
					this->Cs[y][x] = new Cell(y, x, new gold(y, x, BLUE, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 's':
					this->Cs[y][x] = new Cell(y, x, new silver(y, x, BLUE, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'k':
					this->Cs[y][x] = new Cell(y, x, new King(y, x, BLUE, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'r':
					this->Cs[y][x] = new Cell(y, x, new rook(y, x, BLUE, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'b':
					this->Cs[y][x] = new Cell(y, x, new bishop(y, x, BLUE, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'p':
					this->Cs[y][x] = new Cell(y, x, new pawn(y, x, BLUE, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'L':
					this->Cs[y][x] = new Cell(y, x, new lance(y, x, BLACK, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'H':
					this->Cs[y][x] = new Cell(y, x, new knight(y, x, BLACK, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'G':
					this->Cs[y][x] = new Cell(y, x, new gold(y, x, BLACK, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'S':
					this->Cs[y][x] = new Cell(y, x, new silver(y, x, BLACK, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'K':
					this->Cs[y][x] = new Cell(y, x, new King(y, x, BLACK, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'R':
					this->Cs[y][x] = new Cell(y, x, new rook(y, x, BLACK, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'B':
					this->Cs[y][x] = new Cell(y, x, new bishop(y, x, BLACK, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				case 'P':
					this->Cs[y][x] = new Cell(y, x, new pawn(y, x, BLACK, this));
					if (n[y][z + 1] == 'z')
						this->Cs[y][x]->getpc()->setpromo(true);
					break;
				default:
					this->Cs[y][x] = new Cell(y, x, nullptr);

					break;
				}

			}
		}

		b = true;
	}
	else
	{
	b = false;
     }

}

void Board::writer(ofstream& wtr)
	{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (Cs[y][x]->getpc()!=nullptr)
			{
				switch (Cs[y][x]->getpc()->t)
				{
				case 'l':
					 (this->Cs[y][x]->getpc()->getclr() == BLACK) ? wtr << 'L' : wtr << 'l';
					 (this->Cs[y][x]->getpc()->getpromo()) ? wtr << 'z' : wtr << 'o';
					break;
				case 'h':
					 (this->Cs[y][x]->getpc()->getclr() == BLACK) ? wtr << 'H' : wtr << 'h';
					 (this->Cs[y][x]->getpc()->getpromo()) ? wtr << 'z' : wtr << 'o';
					 break;
				case 'g':
					 (this->Cs[y][x]->getpc()->getclr() == BLACK) ? wtr << 'G' : wtr << 'g';
					 (this->Cs[y][x]->getpc()->getpromo()) ? wtr << 'z' : wtr << 'o';
					 break;
				case 's':
					 (this->Cs[y][x]->getpc()->getclr() == BLACK) ? wtr << 'S' : wtr << 's';
					 (this->Cs[y][x]->getpc()->getpromo()) ? wtr << 'z' : wtr << 'o';
					break;
				case 'k':
					 (this->Cs[y][x]->getpc()->getclr() == BLACK) ? wtr << 'K' : wtr << 'k';
					 (this->Cs[y][x]->getpc()->getpromo()) ? wtr << 'z' : wtr << 'o';
					break;
				case 'r':
					 (this->Cs[y][x]->getpc()->getclr() == BLACK) ? wtr << 'R' : wtr << 'r';
					 (this->Cs[y][x]->getpc()->getpromo()) ? wtr << 'z' : wtr << 'o';
					break;
				case 'b':
					 (this->Cs[y][x]->getpc()->getclr() == BLACK) ? wtr << 'B' : wtr << 'b';
					 (this->Cs[y][x]->getpc()->getpromo()) ? wtr << 'z' : wtr << 'o';
					break;
				case 'p':
					 (this->Cs[y][x]->getpc()->getclr() == BLACK) ? wtr << 'P' : wtr << 'p';
					 (this->Cs[y][x]->getpc()->getpromo()) ? wtr << 'z' : wtr << 'o';
					break;
					
				default:
					wtr << '-';
					wtr << 'o';
					break;
				}
			}
			else
			{
				wtr << '-';
				wtr << 'o';

			}
		}
		wtr << endl;
	}
	
}



Board::Board(Board* bo)
{
	Cs = new Cell * *[9];
	
	for (int r = 0; r < 9; r++)
	{
		Cs[r] = new Cell * [9];
		for (int c = 0; c < 9; c++)
		{
			this->Cs[r][c] = new Cell(*bo->Cs[r][c]);
			this->Cs[r][c]->setpc(bo->Cs[r][c]->getpc());
		}
	}

}

void Board::drawboard()
{

	int pl[8], pt[8], pr[8], pb[8];

	pl[1] = 0; pl[0] = 0;
	pl[3] = 30; pl[2] = 30;
	pl[5] = 30 + (65 * 9); pl[4] = 30;
	pl[7] = 60 + (65 * 9); pl[6] = 0;

	pt[1] = 0; pt[0] = 0;
	pt[3] = 30; pt[2] = 30;
	pt[5] = 30; pt[4] = 30 + (65 * 9);
	pt[7] = 0; pt[6] = 60 + (65 * 9);

	pr[1] = 0; pr[0] = 60 + (65 * 9);
	pr[3] = 30; pr[2] = 30 + (65 * 9);
	pr[5] = 30 + (65 * 9); pr[4] = 30 + (65 * 9);
	pr[7] = 60 + (65 * 9); pr[6] = 60 + (65 * 9);

	pb[7] = 30 + (65 * 9); pb[6] = 30;
	pb[5] = 60 + (65 * 9); pb[4] = 0;
	pb[1] = 30 + (65 * 9); pb[0] = 30 + (65 * 9);
	pb[3] = 60 + (65 * 9); pb[2] = 60 + (65 * 9);
	setfillstyle(1, RGB(253, 190, 19));
	setcolor(BLACK);
	fillpoly(4, pl);
	fillpoly(4, pt);
	fillpoly(4, pr);
	fillpoly(4, pb);
	
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			
			Cs[r][c]->draw(r, c);
			
		}
		cout << endl;
	}
}

Piece* Board::getpiece(int sr,int sc)
{
	return this->Cs[sr][sc]->Pc;
}
void Board::Move(int sr, int sc, int dr, int dc, Cell** x)
{
	if (x != nullptr && Cs[dr][dc]->getpc() != nullptr)
	{
		Color m = (Cs[dr][dc]->getpc()->getclr() == BLACK) ?  BLUE: BLACK;
		switch (Cs[dr][dc]->getpc()->t)
		{
		case 'l':
			x[0]->setpc(Cs[dr][dc]->getpc());
			x[0]->getpc()->setpromo(0);
			x[0]->getpc()->setclr(m);
			x[0]->getpc()->count++;
			break;
		case 'h':
			x[1]->setpc(Cs[dr][dc]->getpc());
			x[1]->getpc()->setpromo(0);
			x[1]->getpc()->setclr(m);
			x[1]->getpc()->count++;
			break;
		case 'g':
			x[2]->setpc(Cs[dr][dc]->getpc());
			x[2]->getpc()->setpromo(0);
			x[2]->getpc()->setclr(m);
			x[2]->getpc()->count++;
			break;
		case 's':
			x[3]->setpc(Cs[dr][dc]->getpc());
			x[3]->getpc()->setpromo(0);
			x[3]->getpc()->setclr(m);
			x[3]->getpc()->count++;
			break;

		case 'r':
			x[4]->setpc(Cs[dr][dc]->getpc());
			x[4]->getpc()->setpromo(0);
			x[4]->getpc()->setclr(m);
			x[4]->getpc()->count++;
			break;
		case 'b':
			x[5]->setpc(Cs[dr][dc]->getpc());
			x[5]->getpc()->setpromo(0);
			x[5]->getpc()->setclr(m);
			x[5]->getpc()->count++;
			break;
		case 'p':
			x[6]->setpc(Cs[dr][dc]->getpc());
			x[6]->getpc()->setpromo(0);
			x[6]->getpc()->setclr(m);
			x[6]->getpc()->count++;
			break;
		}
	}

	{
		this->Cs[dr][dc]->setpc(this->Cs[sr][sc]->getpc());

		this->Cs[sr][sc]->setpc(nullptr);
	}
}
bool Board:: islegalmove(Board*to,int sr, int sc ,int dr, int dc)
{
	Piece* t = this->Cs[sr][sc]->Pc;
	
	if(t!=nullptr)
	return (this->Cs[sr][sc]->getpc())->islegal(to,sr, sc, dr, dc);

	
}