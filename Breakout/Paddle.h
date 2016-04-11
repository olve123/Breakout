#pragma once
#include "Piece.h"
class Paddle :
	public Piece
{
public:
	Paddle();
	Paddle(int xPos, int yPos, int height, int length, uint32_t color);
	~Paddle();
	void moveRight(int x);
	void moveLeft(int x);

};

