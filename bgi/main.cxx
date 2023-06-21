/*******************************************************************************
* eyes.exe  Flicker-free, mouse-following, customizably-colored eyes.
* Copyright (C) 1998 Grant Macklem
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software Foundation,
* Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*
* You may contact me, the author by emailing Grant.Macklem@Colorado.EDU
*******************************************************************************/

#include "graphics.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>                     // Provides exit
#include <ctype.h>                      // Provides toupper

#include<string>
#include<string.h>
#include "Shogi.h"
using namespace std;


string therealquestion()
{
	
	string n="Newload.txt";
	
	readimagefile("bg.gif", 0, 0, 1300, 900);
	setfillstyle(1, RGB(255, 205, 129));
	
	readimagefile("Newgame.gif", 80, 430, 480, 570);
	readimagefile("Loadgame.gif", 800, 400, 1200, 580);
	readimagefile("backr.gif", 100, 30, 1100, 160);
	setfillstyle(1, BLACK);
	bar3d(190, 60, 1030, 140,0,0);
	settextstyle(2, 0, 8);
	setcolor(RGB(255, 64, 39));
	bgiout << "RULES [spacebar for next]";
	outstreamxy(350, 70);
	settextstyle(2, 0, 8);
	bgiout << "SPACEBAR FOR RULE";
	outstreamxy(290, 100);
	int r = 0, c = 0,i=0;
	while(true)
	{
		

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, c, r);
			if (r > 430 && r < 570 && c>80 && c < 480)
			{
				n = "Newload.txt";
				break;
			}
			if (r > 400 && r < 580 && c>800 && c < 1200)
			{

				n = "Save.txt";
				break;
			}
		}

		
		if (kbhit())
		{
			char k = getch();
			if(k==32)
			i++;


			if (i == 1)
			{
				settextstyle(2, 0, 8);
				bgiout << "Pawn moves 1 step ahead                                                                 ";
				outstreamxy(290, 100);
			}
			if (i == 2)
			{
				settextstyle(2, 0, 8);
				bgiout << "bishop moves diagonally                                                                  ";
				outstreamxy(290, 100);
			}
			if (i == 3)
			{
				settextstyle(2, 0, 8);
				bgiout << "rook moves up,down,left,right                                          ";
				outstreamxy(290, 100);
			}
			if (i == 4)
			{
				settextstyle(2, 0, 8);
				bgiout << "lance moves forward only                                                                 ";
				outstreamxy(290, 100);
			}
			if (i == 5)
			{
				settextstyle(2, 0, 8);
				bgiout << "knight moves in L shape forward                                                     ";
				outstreamxy(290, 100);
			}
			if (i == 6)
			{
				settextstyle(2, 0, 8);
				bgiout << "silver moves 1 step vertical and diagonal                                    ";
				outstreamxy(290, 100);
			}
			if (i ==7)
			{
				settextstyle(2, 0, 8);
				bgiout << "gold moves 1 step diagonal ahead, vertical and horicontal";
				outstreamxy(290, 100);
			}
			if (i == 8)
			{
				settextstyle(2, 0, 8);
				bgiout << "king moves like silver but horizontal too                                      ";
				outstreamxy(290, 100);
			}

			if (i == 9)
			{
				i = 0;
				continue;

			}
			
		}
				
			
		
	
	}
	
	return n;
}

int main()
{
	bool wannaplay = true;
	while (wannaplay)
	{
		string Nl;

		
		bool tell;
		int win_id = initwindow(1300, 900);
		Nl = therealquestion();
		
		Shogi S;
		S.makeShogi(Nl, tell);
	
		if (tell == true)
		{
			int orgwin = initwindow(1300, 900, "Shogi Game");
			S.play(orgwin);
		}
		else
		{
			int win_id2 = initwindow(900, 900);
			settextstyle(2, 0, 9);
			bgiout << "COULDNT LOAD GAME";
			outstreamxy(100, 300);
			bgiout << "CLICK ANYWHERE OR PRESS A KEY ";
			outstreamxy(100, 400);


			while (true)
			{
				if (ismouseclick(WM_LBUTTONDOWN))
				{
					closegraph(win_id2);
					break;
				}
			}
		}
		int win_ask = initwindow(900, 500);
		readimagefile("ask.jpg", 0, 0, 900, 500);
		/*bar3d(345, 200, 596, 271,0,0);*/
		int mr = 0, mc = 0;
		while (true)
		{
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, mc, mr);
				if(mc>=345&&mc<=596&&mr>=130&&mr<=200)
				{
					closegraph(win_ask);
					setcurrentwindow(win_id);
					wannaplay = true;
					break;
				}
				if(mc>=345&&mc<=596&&mr>=200&&mr<=271)
				{
					closegraph(win_ask);
					closegraph(win_id);
					wannaplay = false;
					break;
				}
				
			}
		}
	
	}
	return 0;
}


