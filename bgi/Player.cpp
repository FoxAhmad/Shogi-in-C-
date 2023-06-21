#include "Player.h"
#include <string>
using namespace std;

Player::Player(string _n, Color _C)
{
	name = _n;
	C = _C;
}
string Player:: getname()
{
	return name;
}
Color Player::getcolor()
{
	return C;
}
void Player::setname(string v)
{
	this->name = v;
}
