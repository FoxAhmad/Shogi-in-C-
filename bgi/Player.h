#pragma once
#include<string>
#include"Header.h"
using namespace std;

class Player
{
	string name;
	Color C;
	int score;
public:
	Player(string _n, Color _C);
	string getname();
	Color getcolor();
	void setname(string);
};

