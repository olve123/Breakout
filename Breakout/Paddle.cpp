#include "Paddle.h"
#include "Common.h"


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
	m_rect.x += x *2;
	if ((m_rect.x + m_length) > SCREEN_WIDTH)
		m_rect.x = (SCREEN_WIDTH - m_length);
	
}

void Paddle::moveLeft(int x)
{
	m_rect.x -= x*2;
	if (m_rect.x < - 100)
		m_rect.x = -90;
}

SDL_Rect Paddle::getRect() {
	return m_rect;
}

