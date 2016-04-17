#ifndef PADDLE_H
#define PADDLE_H

#include "Common.h"
#include "Square.h"
class Paddle : public Square
{
public:
	Paddle();
	Paddle(int xPos, int yPos, int height, int length, Uint32 color);
	void moveRight(int x);
	void moveLeft(int x);
	SDL_Rect getRect();
	
private:
	int m_hp;

};

#endif // !PADDLE_H