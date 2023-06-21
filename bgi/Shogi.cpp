#include "Shogi.h"
#include "Piece.h"
#include "Cell.h"
#include "Board.h"
#include "Player.h"
#include "graphics.h"
#include "king.h"
#include <time.h>
#include "pawn.h"
#include "lance.h"
#include "knight.h"
#include "bishop.h"
#include "silver.h"
#include "gold.h"
#include"rook.h"
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
void Shogi:: getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}

Shogi::Shogi()
{
}
void Shogi::makeShogi(string &bo,bool&teller)
{
	bool canplay = true;
		ifstream rdr(bo);
	b = new Board(rdr, canplay);
	if (canplay)
	{
		teller = true;
		Pls = new Player * [2];
		if (bo == "Save.txt")
		{
			char dr;
			string n, m;
			rdr >> turn;
			rdr >> n;
			Pls[0] = new Player(n, BLACK);
			rdr.ignore();
			rdr >> m;
			Pls[1] = new Player(m, BLUE);
			rdr.ignore();
			drops = new Cell * *[2];
			drops[0] = new Cell * [7];
			drops[1] = new Cell * [7];
			
			for (int y = 0; y < 7; y++)
			{
				rdr >> dr;
				switch (dr)
				{

				case 'L':
					drops[0][y] = new Cell(405, y * 60 + 810, new lance(0, 0, BLACK, b));

					break;
				case 'H':
					drops[0][y] = new Cell(405, y * 60 + 810, new knight(0, 0, BLACK, b));

					break;
				case 'G':
					drops[0][y] = new Cell(405, y * 60 + 810, new gold(0, 0, BLACK, b));

					break;
				case 'S':
					drops[0][y] = new Cell(405, y * 60 + 810, new silver(0, 0, BLACK, b));

					break;


				case 'R':
					drops[0][y] = new Cell(405, y * 60 + 810, new rook(0, 0, BLACK, b));

					break;
				case 'B':
					drops[0][y] = new Cell(405, y * 60 + 810, new bishop(0, 0, BLACK, b));

				case 'P':
					drops[0][y] = new Cell(405, y * 60 + 810, new pawn(0, 0, BLACK, b));

					break;
				case'-':
					drops[0][y] = new Cell(140520, y * 60 + 810, nullptr);
					break;
				}
			}
			for (int y = 0; y < 7; y++)
			{
				rdr >> dr;
				switch (dr)
				{

				case 'l':
					drops[1][y] = new Cell(120, y * 60 + 810, new lance(0, 0, BLUE, b));

					break;
				case 'h':
					drops[1][y] = new Cell(120, y * 60 + 810, new knight(0, 0, BLUE, b));

					break;
				case 'g':
					drops[1][y] = new Cell(120, y * 60 + 810, new gold(0, 0, BLUE, b));

					break;
				case 's':
					drops[1][y] = new Cell(120, y * 60 + 810, new silver(0, 0, BLUE, b));

					break;


				case 'r':
					drops[1][y] = new Cell(120, y * 60 + 810, new rook(0, 0, BLUE, b));

					break;
				case 'b':
					drops[1][y] = new Cell(120, y * 60 + 810, new bishop(0, 0, BLUE, b));

				case 'p':
					drops[1][y] = new Cell(120, y * 60 + 810, new pawn(0, 0, BLUE, b));

					break;
				case'-':
					drops[1][y] = new Cell(120, y * 60 + 810, nullptr);
					break;
				}
			}
		 }
		else
		{

			 initwindow(1000, 600);
			
			setfillstyle(1, BLACK);
	
			settextstyle(2, 0, 8);
			
			
			string n1, n2; char ch = 0; int x = 0; int i = 0;
			char h[12] = {};
			settextstyle(BOLD_FONT, 0, 4);
			readimagefile("pl1bg.jpg", 0, 0, 1000, 600);
			
		
			
			do

			{


				ch = (char)getch();
				if (ch != (int)13)
				{
					settextstyle(BOLD_FONT, 0, 4);
					bgiout << (char)ch;
					outstreamxy(490 + x, 320);
					h[i] = ch;

					i++;
				}
				x += 30;
				if (i > 11)
					break;
				

			} while ((ch != 13));
			n1 = h;
			for (int hi = 0; hi < 12; hi++)
			{
				h[hi] = 0;
			}
			x = 0; i = 0;
			readimagefile("Player1.jpg", 0, 0, 1000, 600);
			
			do

			{

				ch = (char)getch();
				if (ch != (int)13)
				{
					settextstyle(BOLD_FONT, 0, 4);
					bgiout << (char)ch;
					outstreamxy(490 + x, 350);
					h[i] = (char)ch;
					i++;
				}
				x += 30;
				if (i > 11)
					break;
				


			} while ((ch != 13));
			n2 = h;
			if (n1.length() > 0)
			{
				Pls[0] = new Player(n1, BLACK);

			}
			if (n2.length() > 0)
			{
				Pls[1] = new Player(n2, BLUE);
			}
			if (n1.length() <= 0)
			{
				Pls[0] = new Player("BLACK PLAYER(0)", BLACK);
			}
			if (n2.length() <= 0)
			{
				Pls[1] = new Player("WHITE PLAYER(1)", BLUE);
			}
			readimagefile("versus.gif", 0, 0, 1000, 600);
			bgiout << Pls[0]->getname();
			outstreamxy(250,450);
			bgiout << Pls[1]->getname();
			outstreamxy(630, 450);
			delay(3000);
			closegraph();
			srand(time(0));
			turn = rand() % 2;
			drops = new Cell * *[2];
			drops[0] = new Cell * [7];
			drops[1] = new Cell * [7];
			for (int y = 0; y < 7; y++)
			{

				drops[1][y] = new Cell(120, y * 60 + 810, nullptr);
				drops[0][y] = new Cell(405, y * 60 + 810, nullptr);
			}

		}
	}
	else
	{
		teller = false;
		return;
	}

}
bool Shogi::isvalidSel(int sr, int sc, Player* AP, Board* b)
{
	
	
	{
		if (sr < 0 || sc>8 || sc < 0 || sr>8)
			return false;
		if (b->Cs[sr][sc]->getpc() == nullptr)
			return false;
		return ((b->Cs[sr][sc]->getpc())->getclr() == AP->getcolor());
	}
}
bool Shogi::isvaliddest( int dr, int dc, Player* AP ,Board* b)
{
	

	if (dr < 0 || dc>8 || dc < 0 || dr>8)
		return false;
	if (b->Cs[dr][dc]->getpc() == nullptr)
		return true;
    return !((b->Cs[dr][dc]->getpc())->getclr() == AP->getcolor());
}
void Shogi::selection(Player* p, bool& ds)
{
	/*cin >> sri >> sci;*/
	int r = 0, c = 0;
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, c, r);
			break;
		}
	}
	if (c >= 810 && c <= 1230 && ((r >= 120 && r <= 180 && p->getcolor() == BLUE) || ((r >= 405 && r <= 465) && p->getcolor() == BLACK)))
	{
		ds = true;
		if (r >= 405 && r <= 465)
			sri = 0;
		else if (r >= 120 && r <= 180)
			sri = 1;
		sci = (c-810)/60;
		return;
	}
	else
	{
		ds = false;
		sri = (r - 30) / 65;
		sci = (c - 30) / 65;
	}
}
void Shogi::destination()
{
	//cin >> dri >> dci;
	int r = 0, c = 0;
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, c, r);
			break;
		}
	}
	dri = (r - 30)/65;
	dci = (c -30)/65;

}
void Shogi::turnmessage(Player* AP)
{
	setcolor(BLACK);
	setfillstyle(1, BLACK);
	fillellipse(750, 500, 25, 25);
	fillellipse(750, 100, 25, 25);


	setcolor(BLACK);
	setfillstyle(1, RGB(250,0,0));
	(AP->getcolor() == BLACK) ? fillellipse(750, 500, 25, 25) : fillellipse(750, 100, 25, 25);
	


}
void Shogi::changeturn()
{
	turn=!turn;
}
void Shogi::Highlight(Board* b, int sri, int sci, Player** p,int turn)
{
	for (int _ri = 0; _ri < 9; _ri++)
	{
		for (int _ci = 0; _ci < 9; _ci++)
		{
			if ( isvaliddest(_ri, _ci, p[turn], b) && b->islegalmove(b,sri, sci, _ri, _ci) && !(Selfcheck(b, turn, sci, sri, _ci, _ri, p)))
			{
				if (b->Cs[_ri][_ci]->getpc() != nullptr && b->Cs[_ri][_ci]->getpc()->getclr() != p[turn]->getcolor())
				{
					setfillstyle(1, RGB(0, 250, 0));
					setcolor(BLACK);
					bar3d(_ci * 65+30, _ri * 65+30, _ci * 65 + 65+30, _ri * 65 + 65+30, 0, 0);
					(b->Cs[_ri][_ci]->getpc())->draw(_ri*65+32+30,_ci*65+32+30);
				}
				else
				{
					setfillstyle(1, RGB(0, 250, 0));
				    setcolor(BLACK);
				
				    fillellipse(b->Cs[_ri][_ci]->c * 65 + 32+30, b->Cs[_ri][_ci]->r * 65 + 32+30, 10, 10);
				}
			}
		}
	}
}
void Shogi::UnHighlight(Board* b, int sri, int sci, Player** p,int turn)
{
	for (int _ri = 0; _ri < 9; _ri++)
	{
		for (int _ci = 0; _ci < 9; _ci++)
		{
			if (   isvaliddest(_ri, _ci, p[turn], b) && b->islegalmove(b,sri, sci, _ri, _ci) && !(Selfcheck(b, turn, sci, sri, _ci, _ri, p)))
			{
				
				b->Cs[_ri][_ci]->draw(_ri, _ci);
			}
		}
	}
}
void Shogi::findking(Board* b,Player*p, int& Kr, int& Kc)
{
	 
		for (int r = 0; r < 9; r++)
		{
			for (int c = 0; c < 9; c++)
			{
				King* kptr = dynamic_cast <King*>(b->getpiece(r, c));
				if (kptr != nullptr && kptr->getclr() == p->getcolor() )
				{
					Kr = r;
					Kc = c;
					return;
				}
			}
		}
	
}

bool Shogi::Check(Board*b,int turn ,Player**p)
{
	int Kr = 0, Kc = 0;
	
	findking(b,p[!turn], Kr, Kc);
    
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			if (isvalidSel(r,c,p[turn], b) && b->islegalmove(b,r, c, Kr, Kc))
			{
				return true;
			}
		}
	}
	return false;

}

bool Shogi::Selfcheck(Board*b, int turn, int sci, int sri, int dci, int dri,Player**p)
{
	Board t(b);
	Board* tp = &t;
	tp->Move(sri, sci, dri, dci,nullptr);
	/*initwindow(1200, 1200);
	t->drawboard();*/
    return (Check(tp, !turn,p));
}

bool Shogi::CaniMove(Board*b, int turn,Player**p)
{
	Board tb(b);
	Board* t = &tb;
	for (int sr = 0; sr < 9; sr++)
	{
		for (int sc = 0; sc < 9; sc++)
		{
			for (int dr = 0; dr < 9; dr++)
			{
				for (int dc = 0; dc < 9; dc++)
				{
					if (isvalidSel(sr,sc,p[turn], t) && isvaliddest(dr, dc, p[turn], t) && t->islegalmove(t,sr, sc, dr, dc) && !Selfcheck(t, turn, sc, sr, dc, dr, p))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Shogi::Save(Board* b, string s)
{
	ofstream wtr(s);
	b->writer(wtr);
	
	wtr << turn;
	wtr << endl;
	wtr << Pls[0]->getname();
	wtr << endl;
	wtr << Pls[1]->getname();
	wtr << endl;
	for (int x = 0; x < 7; x++)
	{
		if (drops[0][x]->getpc() != nullptr)
		{
			switch (drops[0][x]->getpc()->t)
			{
			case 'l':
				wtr << 'L' ;

				break;
			case 'h':
				 wtr << 'H';

				break;
			case 'g':
				wtr << 'G';

				break;
			case 's':
				 wtr << 'S';

				break;
		
				
			case 'r':
				wtr << 'R';

				break;
			case 'b':
			 wtr << 'B';

			case 'p':
				 wtr << 'P';

				break;


			}
		}
		else
		{
			wtr << '-';


		}
	}
	wtr << endl;
	for (int x = 0; x < 7; x++)
	{
		if (drops[1][x]->getpc() != nullptr)
		{
			wtr << (drops[1][x]->getpc()->t);
		}
		else
		{
			wtr << '-';


		}
	}
	wtr << endl;
	
}

bool Shogi::dropdest(int dr, int dc, Board* b)
{
	if (dr < 0 || dc>8 || dc < 0 || dr>8)
		return false;
	if (b->Cs[dr][dc]->getpc() == nullptr)
		return true;
	if (b->Cs[dr][dc]->getpc() != nullptr)
		return false;
}
bool Shogi::dropselect(int sr, int sc, Cell** cs)
{
	if (sr < 0 || sc>7 || sc < 0 || sr>7)
		return false;
	if (cs[sc]->getpc() == nullptr)
		return false;
	if (cs[sc]->getpc() != nullptr)
		return true;
}
bool Shogi::droplegal(int sr, int sc, int dr, int dc, Cell** p, Board* b,int turn,Player**Pa)
{
	Board temp (b);
	Board* tb = &temp;
	tb->Cs[dr][dc]->setpc(p[sc]->getpc());
	if (/*Check(tb, turn, Pa)==false&&*/CaniMove(tb,!turn,Pa)==true)
	{
		
			for (int c = 0; c < 9; c++)
			{
				for (int r = 0; r < 9; r++)
				{
				if ((isvaliddest(r, c, Pa[turn], tb) && tb->islegalmove(tb,dr, dc, r, c))==true)
				{
					if (tb->getpiece(dr, dc)->t == 'p')
					{
						
							for (int ro = 0; ro < 9; ro++)
							{
								pawn* pptr = dynamic_cast <pawn*>(tb->getpiece(ro, c));

								if ((dr!=ro )&&pptr != nullptr && tb->getpiece(ro, c)->getclr() == Pa[turn]->getcolor() && tb->getpiece(ro, c)->getpromo() == false)
								{
									return false;
								}


							}
						
					}
					return true;
					
				}

			}
		}
	}
	
	
	return false;
	
	
}
void Shogi::drophl(Board* b, int sr, int sc, Cell** p, int tr,Player**Pa)
{
	for (int dro = 0; dro < 9; dro++)
	{
		for (int dco = 0; dco < 9; dco++)
		{
			if (dropdest(dro, dco, b) && droplegal(sr, sc, dro, dco, p, b, tr, Pa))
			{
				setfillstyle(1, RGB(0, 250, 0));
				setcolor(BLACK);

				fillellipse(dco * 65 + 32 + 30, dro * 65 + 32 + 30, 10, 10);
			}
		}
	}
}
void Shogi::undrophl(Board* b, int sr, int sc, Cell** p, int tr, Player** Pa)
{
	for (int dro = 0; dro < 9; dro++)
	{
		for (int dco = 0; dco < 9; dco++)
		{
			if (dropdest(dro, dco, b) && droplegal(sr, sc, dro, dco, p, b, tr, Pa))
			{
				b->Cs[dro][dco]->draw(dro, dco);
			}
		}
	}
}
void Shogi::dropmove(Board* b, int sr, int sc, int dr, int dc, Cell** x)
{
	b->Cs[dr][dc]->setpc(x[sc]->getpc());
	x[sc]->getpc()->count--;
	if (x[sc]->getpc()->count == 0)
	{
		
		x[sc]->setpc( nullptr) ;
		
	}
}


void Shogi::play(int orgwin)
{
	
	ofstream wtr("Save.txt");
	b->drawboard();
	//shashkay
	{setcolor(WHITE);
	settextstyle(2, 0, 8);
	bgiout << Pls[0]->getname();
	outstreamxy(800, 490);
	bgiout << Pls[1]->getname();
	outstreamxy(800, 90);
	bgiout << "THESE ARE CAPTURED PIECES";
	outstreamxy(790, 250);
	bgiout << "YOU CAN DROP THEM IN BOARD";
	outstreamxy(790, 280);
	}
	
	//drops
	{
		
		for (int y = 0; y < 7; y++)
		{
			setcolor(RGB(0, 0, 0));
			setfillstyle(1, RGB(253, 190, 19));
			bar3d(drops[1][y]->c, drops[1][y]->r, drops[1][y]->c + 60, drops[1][y]->r + 60, 0, 0);
			bar3d(drops[0][y]->c, drops[0][y]->r, drops[0][y]->c + 60, drops[0][y]->r + 60, 0, 0);
		}
		for (int y = 0; y < 7; y++)
		{
			if (drops[turn][y]->getpc() != nullptr)
			{
				drops[turn][y]->getpc()->draw(drops[turn][y]->r + 30, drops[turn][y]->c + 30);
			}
			else if (drops[turn][y]->getpc() == nullptr)
			{
				setfillstyle(1, RGB(253, 190, 19));
				bar3d(drops[turn][y]->c, drops[turn][y]->r, drops[turn][y]->c + 60, drops[turn][y]->r + 60, 0, 0);
			}
			if (drops[!turn][y]->getpc() != nullptr)
			{
				drops[!turn][y]->getpc()->draw(drops[!turn][y]->r + 30, drops[!turn][y]->c + 30);
			}
		
		}

	}
	int kc = 0, kr = 0; bool kch = false;
	while (true)
	{
		bool sel=false;
		bool dest=false;
		bool dropsel=false;
		turnmessage(Pls[turn]);

		do
		{

			do
			{

				selection(Pls[turn],dropsel);
				if (kch)
				{
					b->Cs[kr][kc]->draw(kr, kc);
					kr = 0; kc = 0;
					kch = false;
				}
				if (dropsel == false)
					sel = !isvalidSel(sri, sci, Pls[turn], b);
				else
					sel = false;

			} while (sel ||(dropsel&&!dropselect(sri,sci,drops[turn])));

			if (dropsel)
				drophl(b, sri, sci,drops[turn], turn,Pls);
			else
			Highlight(b, sri, sci, Pls, turn);


			destination();
			if (dropsel == false)
				dest = ((!isvaliddest(dri, dci, Pls[turn], b) || !(b->islegalmove(b,sri, sci, dri, dci)) || (Selfcheck(b, turn, sci, sri, dci, dri, Pls))));
			else
				dest = false;
			if (dropsel)
				undrophl(b, sri, sci , drops[turn], turn, Pls);
			else
			UnHighlight(b, sri, sci, Pls, turn);
		} while (dest || (dropsel && (!dropdest(dri, dci, b) || !droplegal(sri, sci, dri, dci, drops[turn], b, turn, Pls))));

		//MOVE
		{
			if (dropsel)
			{
				dropmove(b, sri, sci, dri, dci, drops[turn]);
			}
			else
			b->Move(sri, sci, dri, dci, drops[turn]);
			for (int y = 0; y < 7; y++)
			{
				if (drops[turn][y]->getpc() != nullptr)
				{
					drops[turn][y]->getpc()->draw(drops[turn][y]->r + 30, drops[turn][y]->c + 30);
				}
				else if(drops[turn][y]->getpc() == nullptr)
				{
					setfillstyle(1, RGB(253, 190, 19));
					bar3d(drops[turn][y]->c, drops[turn][y]->r, drops[turn][y]->c + 60, drops[turn][y]->r + 60, 0, 0);
				}
			}

		}
		//PROMOTION
		{
			if ((Pls[turn]->getcolor() == BLACK && ((dropsel==false && dri <= 2 && b-> Cs[dri][dci]->getpc()->getpromo()==false))))
			{
				int win_id4 = initwindow(500, 500, "MARZI HAI BHAI");
				settextstyle(2, 0, 8);
				bgiout << "CHOOSE";
				outstreamxy(180, 0);
				settextstyle(2, 0, 7);
				setcolor(RGB(255, 0, 0));
				bgiout << "PROMOTED";
				outstreamxy(30, 50);
				settextstyle(2, 0, 7);
				setcolor(WHITE);
				bgiout << "NORMAL";
				outstreamxy(300, 50);
				setfillstyle(1, RGB(253, 190, 19));
				bar3d(10, 100, 220, 400, 0, 0);
				bar3d(280, 100, 480, 400, 0, 0);
				switch (b->Cs[dri][dci]->getpc()->t)
				{
				case 'l':
					readimagefile("Bpromolance.gif", 70, 140, 170, 310);
					readimagefile("lanceB.gif", 320, 150, 440, 300);
					break;
				case 'h':
					readimagefile("Bpromoknight.gif", 50, 140, 180, 300);
					readimagefile("Bhorse.gif", 320, 150, 440, 300);
					break;

				case 's':
					readimagefile("Bpromosilver.gif", 50, 150, 180, 300);
					readimagefile("silvergenB.gif", 320, 150, 440, 300);
					break;

				case 'r':
					readimagefile("Bpromorook.gif", 50, 150, 180, 300);
					readimagefile("Brook.gif", 320, 150, 440, 300);
					break;
				case 'b':
					readimagefile("Bpromobishop.gif", 50, 150, 180, 300);
					readimagefile("Bbishop.gif", 320, 150, 440, 300);
					break;
				case 'p':
					readimagefile("Bpromopawn.gif", 50, 150, 180, 300);
					readimagefile("Bpawn.gif", 340, 150, 420, 300);
					break;
				}

				while (true)
				{

					if (ismouseclick(WM_LBUTTONDOWN))
					{
						int r = 0, c = 0;
						getmouseclick(WM_LBUTTONDOWN, c, r);

						if (r > 99 && r < 401 && c > 9 && c < 221)
						{
							b->Cs[dri][dci]->getpc()->setpromo(1);


							break;
						}
						else if (r > 99 && r < 401 && c > 279 && c < 481)
						{
							b->Cs[dri][dci]->getpc()->setpromo(0);



							break;
						}

					}

				}
				closegraph(win_id4);
				setcurrentwindow(orgwin);

			}

			if ((Pls[turn]->getcolor() == BLUE && ((dropsel == false && dri >= 6 && b->Cs[dri][dci]->getpc()->getpromo() == false))))
			{
				int win_id4 = initwindow(500, 500, "");
				settextstyle(2, 0, 8);
				bgiout << "CHOOSE";
				outstreamxy(180, 0);
				settextstyle(2, 0, 7);
				setcolor(RGB(255, 0, 0));
				bgiout << "PROMOTED";
				outstreamxy(30, 50);
				settextstyle(2, 0, 7);
				setcolor(WHITE);
				bgiout << "NORMAL";
				outstreamxy(300, 50);
				setfillstyle(1, RGB(253, 190, 19));
				bar3d(10, 100, 220, 400, 0, 0);
				bar3d(280, 100, 480, 400, 0, 0);
				switch (b->Cs[dri][dci]->getpc()->t)
				{
				case 'l':
					readimagefile("Wpromolance.gif", 70, 140, 170, 310);
					readimagefile("lanceW.gif", 320, 150, 440, 300);
					break;
				case 'h':
					readimagefile("Wpromoknight.gif", 50, 140, 180, 320);
					readimagefile("Whorse.gif", 320, 150, 440, 300);
					break;

				case 's':
					readimagefile("Wpromosilver.gif", 50, 150, 180, 300);
					readimagefile("silvergenW.gif", 320, 150, 440, 300);
					break;

				case 'r':
					readimagefile("Wpromorook.gif", 50, 150, 180, 300);
					readimagefile("Wrook.gif", 320, 150, 440, 300);
					break;
				case 'b':
					readimagefile("Wpromobishop.gif", 50, 150, 180, 300);
					readimagefile("Wbishop.gif", 320, 150, 440, 300);
					break;
				case 'p':
					readimagefile("Wpromopawn.gif", 70, 150, 170, 300);
					readimagefile("Wpawn.gif", 300, 150, 450, 300);
					break;
				}

				while (true)
				{

					if (ismouseclick(WM_LBUTTONDOWN))
					{
						int r = 0, c = 0;
						getmouseclick(WM_LBUTTONDOWN, c, r);

						if (r > 99 && r < 401 && c > 9 && c < 221)
						{
							b->Cs[dri][dci]->getpc()->setpromo(1);


							break;
						}
						else if (r > 99 && r < 401 && c > 279 && c < 481)
						{
							b->Cs[dri][dci]->getpc()->setpromo(0);



							break;
						}

					}

				}
				closegraph(win_id4);
				setcurrentwindow(orgwin);

			}

		}

		//MOVED DRAW
		{
		  b->Cs[dri][dci]->draw(dri, dci);
		  b->Cs[sri][sci]->draw(sri, sci);
		}
	

		//CHECK DRAW
		{
			setcolor(BLACK);
			bgiout << "                                                  ";
			outstreamxy(860, 50);
			setcolor(BLACK);
			bgiout << "                                                  ";
			outstreamxy(860, 520);
			if (Check(b, turn, Pls))
			{
				kch = true;
				findking(b, Pls[!turn], kr, kc);
				setfillstyle(1, RGB(253, 56, 37));
				bar3d(kc * 65 + 30, kr * 65 + 30, kc * 65 + 95, kr * 65 + 95, 0, 0);
				(b->Cs[kr][kc]->getpc())->draw(kr * 65 + 62, kc * 65 + 62);
				
				
				
				

			}
		}
		//impasse
		{
			bool impasse0=false,impasse1=false,noimpasse=false;
			King* kp0, * kp1;
			int sk0 = 0, sk1 = 0;
			for (int row = 0; row < 9; row++)
			{
				for (int col = 0; col < 9; col++)
				{
					kp0 = dynamic_cast<King*>(b->Cs[row][col]->getpc());
					if (kp0 != nullptr && kp0->getclr() == BLACK && kp0->getpromo() == true)
						impasse0 = true;
					kp1 = dynamic_cast<King*>(b->Cs[row][col]->getpc());
					if (kp1 != nullptr && kp1->getclr() == BLUE && kp1->getpromo() == true)
						impasse1 = true;
					if (impasse1 == true && impasse0 == true)
						break;
				}
				if (impasse1 == true && impasse0 == true)
					break;
			}
			if (impasse1 == true && impasse0 == true)
			{
				int win_id6 = initwindow(800, 500,"");
				readimagefile("textb.jpg", 10, 10, 790, 490);
				settextstyle(BOLD_FONT, 0, 5);
				bgiout << "WANNA DO IMPASSE";
				outstreamxy(270, 180);
				readimagefile("yes.gif", 280, 250, 350, 300);
				readimagefile("no.gif", 500, 250, 570, 300);
				int cr=0, cc=0;
				while (true)
				{
					
					if (ismouseclick(WM_LBUTTONDOWN))
					{
						getmouseclick(WM_LBUTTONDOWN, cc, cr);
						if (cc >=280&&cc<=350 && cr>=250&&cr<=300 )
						{
							
							for (int y = 0; y < 9; y++)
							{
								for (int x = 0; x < 9; x++)
								{
									if (b->Cs[y][x]->getpc() != nullptr)
									{
										switch (b->Cs[y][x]->getpc()->t)
										{
										case'l':
										case'p':
										case's':
										case'g':
										case'h':
											if (b->Cs[y][x]->getpc()->getclr() == BLACK)
											{
												sk0++;
											}
											if (b->Cs[y][x]->getpc()->getclr() == BLUE)
											{
												sk1++;
											}
											break;
										case 'r':
										case'b':
											if (b->Cs[y][x]->getpc()->getclr() == BLACK)
											{
												sk0+=5;
											}
											if (b->Cs[y][x]->getpc()->getclr() == BLUE)
											{
												sk1+=5;
											}
											break;
										default:
											break;

										}
									}
								}
							 }

							for (int x = 0; x < 7; x++)
							{
								if (drops[0][x]->getpc() != nullptr)
								{
									switch (drops[0][x]->getpc()->t)
									{
									case'l':
									case'p':
									case's':
									case'g':
									case'h':
										
											sk0++;
										
										
										break;
									case 'r':
									case'b':
										
										sk0 += 5;
										break;
									default:
										break;

									}
								}
								if (drops[1][x]->getpc() != nullptr)
								{
									switch (drops[1][x]->getpc()->t)
									{
									case'l':
									case'p':
									case's':
									case'g':
									case'h':

										sk1++;


										break;
									case 'r':
									case'b':

										sk1 += 5;
										break;
									default:
										break;

									}
								}
							}
							settextstyle(BOLD_FONT, 0, 4);

							if (sk0 > 24&&sk1<24)
							{
								readimagefile("impasse.jpg", 0, 0, 800, 500);
								bgiout << Pls[0]->getname() << " WINS WITH A SCORE OF: " << sk1;
								outstreamxy(510, 100);
							}
							if (sk1 > 24&&sk0<24)
							{
								readimagefile("impasse.jpg", 0, 0, 800, 500);
								bgiout << Pls[1]->getname() << " WINS WITH A SCORE OF: " << sk1;
								outstreamxy(510, 100);
							}
							if (sk1 <= 24&&sk0<=24)
							{
								readimagefile("impasse.jpg", 0, 0, 800, 500);
								bgiout << "DRAW";
								outstreamxy(510, 100);

							}
							if (sk1 > 24 && sk0 > 24)
							{
								readimagefile("impasse.jpg", 0, 0, 800, 500);
							
								
								(sk1>sk0)? bgiout << Pls[1]->getname() << " WINS WITH A SCORE OF: " << sk1: bgiout << Pls[0]->getname() << " WINS WITH A SCORE OF: " << sk0;
									outstreamxy(510, 100);
							}
						
							delay(4000);
							closegraph(win_id6);
							
							noimpasse = false;
							break;
						}
						else if (cc >= 500 && cc <= 570 && cr >= 250 && cr <= 300)
						{
							closegraph(win_id6);
							setcurrentwindow(orgwin);
							noimpasse = true;
							break;
						}
					}
					if (noimpasse == true)
						break;
				

				}
				
				if (noimpasse == false)
					break;
				
			}
			

		}
		changeturn();
		Save(b, "Save.txt");
		if (!(CaniMove(b, turn, Pls)))
		{
			settextstyle(2, 0, 8);
			setcolor(WHITE);
			bgiout << "CHECK MATE !!!";
			outstreamxy(800, 550);

			bgiout << Pls[!turn]->getname() << " WINS !!!";
			outstreamxy(800, 526);
			delay(5000);
			break;
		}
	}
	
	
}
