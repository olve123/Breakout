#ifndef PADDLE_H
#define PADDLE_H


#include "Piece.h"
class Paddle : public Piece
{
public:
	Paddle();
	Paddle(int xPos, int yPos, int height, int length, Uint32 color);
	~Paddle();
	void moveRight(int x);
	void moveLeft(int x);
	void draw(SDL_Surface* dest);
	
private:
	SDL_Surface *m_image;
	SDL_Rect m_rect;
	int m_hp;

};

#endif // !PADDLE_H