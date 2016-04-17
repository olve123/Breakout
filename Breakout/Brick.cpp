#include "Brick.h"


Brick::Brick()
{
}

Brick::Brick(double xPos, double yPos, int height, int length, Uint32 color, int hp)
	:Square(xPos, yPos, height, length, color)
{

	m_hp = hp;
	m_image = SDL_CreateRGBSurface(0, length, height, 32, 0, 0, 0, 0);
	SDL_FillRect(m_image, NULL, color);
	m_rect.x = static_cast<int>(xPos);
	m_rect.y = static_cast<int>(yPos);
		
}

Brick::~Brick()
{
}

int Brick::getHp()
{
	return m_hp;
}

void Brick::setHp(int hp) {
	m_hp = hp;
}
