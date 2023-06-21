#pragma once
#include <string.h>
#include "Cell.h"
#include<string>
using namespace std;
class Player;

class Pieces;

class Board;

class Shogi
{
	int sri, sci, dri, dci, turn;
	Player* *Pls;
	Cell*** drops;
protected:
	void getRowColbyLeftClick(int& rpos, int& cpos);
	Board* b;
public:
	Shogi();
	void makeShogi(string &bo ,bool&t);
	bool isvalidSel(int, int,  Player* AP,Board* b);
	bool isvaliddest(int , int ,Player* AP, Board* b);
	void selection(Player*,bool&);
	void destination();
	void turnmessage(Player*);
	void changeturn();
	void Highlight(Board*, int, int, Player**,int);
	void UnHighlight(Board*, int, int, Player**,int);
	void findking(Board*, Player*, int&, int&);
	bool Check(Board* ,int turn,Player**);
	bool Selfcheck(Board* b, int turn, int sci, int sri, int dci, int dri, Player* *p);
	bool CaniMove(Board* b, int turn,Player**);
	void Save(Board* ,string wr);
	bool dropdest(int dr, int dc, Board* b);
	void undrophl(Board* b, int sr, int sc, Cell** p, int tr, Player** Pa);
	bool droplegal(int sr, int sc,int dr,int dc,Cell**,Board* ,int turn, Player** Pa);
	void drophl(Board* b, int sr, int sc, Cell** p, int tr,Player**);
	void dropmove(Board*b, int sr, int sc, int dr,int dc, Cell**);
	bool dropselect(int sr, int sc, Cell** cs);
	void play(int);
	


};

