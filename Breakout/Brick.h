#ifndef BRICK_H
#define BRICK_H
/*
*	BRICK 
* 
*/

#include <string>
#include "Square.h"
#include "SDL.h"
using namespace std;

class Brick: public Square {
public:
	Brick();
	Brick(double xPos, double yPos, int height, int length, Uint32 color, int hp);
	~Brick();
	int getHp();
	void setHp(int hp);	

private:
	int m_hp;
};

#endif// !BRICK_H