#ifndef BRICK_H
#define BRICK_H
/*
*	BRICK 
* 
*/

#include <string>
using namespace std;

class Brick: public Piece {
public:
	Brick();
	Brick(int xPos, int yPos, int height, int length, uint32_t color, int hp);
	~Brick();

	int getHp();

	void setHp(int hp);

private:
	int m_hp;
};

#endif// !BRICK_H