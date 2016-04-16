#include "Paddle.h"



Paddle::Paddle()
{
}

Paddle::Paddle(int xPos, int yPos, int height, int length, Uint32 color)
	:Square(xPos, yPos, height, length, color) {
	SDL_FillRect(m_image, NULL, color);
	m_rect.x = xPos;
	m_rect.y = yPos;
}


void Paddle::moveRight(int x)
{
	m_rect.x += x;
}

void Paddle::moveLeft(int x)
{
	m_rect.x -= x;
}

SDL_Rect Paddle::getRect() {
	return m_rect;
}

