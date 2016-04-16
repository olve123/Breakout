#ifndef PADDLE_H
#define PADDLE_H


#include "Square.h"
class Paddle : public Square
{
public:
	Paddle();
	Paddle(int xPos, int yPos, int height, int length, Uint32 color);
	//~Paddle();
	void moveRight(int x);
	void moveLeft(int x);
	SDL_Rect getRect();
	//void draw(SDL_Surface* dest);
	//bool hit();
	//bool miss();
	
private:
	int m_hp;

};

#endif // !PADDLE_H