#ifndef PADDLE_H
#define PADDLE_H


#include "Piece.h"
class Paddle : public Piece
{
public:
	Paddle();
	Paddle(int xPos, int yPos, int height, int length, uint32_t color);
	~Paddle();
	void moveRight(int x);
	void moveLeft(int x);

};

#endif // !PADDLE_H