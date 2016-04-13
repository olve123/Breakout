#include "Paddle.h"



Paddle::Paddle()
{
}

Paddle::Paddle(int xPos, int yPos, int height, int length, Uint32 color)
	:Piece(xPos, yPos, height, length, color) {
	m_image = SDL_CreateRGBSurface(0, length, height, 32, 0, 0, 0, 0);
	SDL_FillRect(m_image, NULL, color);
	m_rect.x = xPos;
	m_rect.y = yPos;
}


Paddle::~Paddle()
{
}

void Paddle::moveRight(int x)
{
	m_rect.x += x;
}

void Paddle::moveLeft(int x)
{
	m_rect.x -= x;
}
void Paddle::draw(SDL_Surface* dest) 
{
	SDL_BlitSurface(m_image, NULL, dest, &m_rect);
}

