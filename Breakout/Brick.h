#ifndef BRICK_H
#define BRICK_H
/*
*	BRICK 
* 
*/

#include <string>
#include "Piece.h"
using namespace std;

class Brick: public Piece {
public:
	Brick();
	Brick(int xPos, int yPos, int height, int length, Uint32 color, int hp);
	~Brick();
	int getHp();
	void setHp(int hp);	
	void draw(SDL_Surface* dest);
	bool hit();
	bool miss();

private:
	SDL_Surface *m_image;
	SDL_Rect m_rect;
	int m_hp;
};

#endif// !BRICK_H