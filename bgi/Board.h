#pragma once
#include <fstream>
using namespace std;
class Cell;
class Piece;
class Board
{

	
	
public:
	Board();
	Board(Board*);
	Board(ifstream & r,bool&);
	Piece* getpiece(int, int);
	bool islegalmove(Board*,int, int, int, int);
	void printgame();
	void drawboard();
	void Move(int,int,int,int,Cell**);
	void writer(ofstream&);
	Cell*** Cs;
};

