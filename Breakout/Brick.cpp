#include "Brick.h"
#include "Piece.h"
#include "SDL.h"

Brick::Brick()
{
}

Brick::Brick(int xPos, int yPos, int height, int length, Uint32 color, int hp)
	:Piece(xPos, yPos, height, length, color)
{
	m_hp = hp;

	m_image = SDL_CreateRGBSurface(0, length, height, 32, 0, 0, 0, 0);
	SDL_FillRect(m_image, NULL, color);
	m_rect.x = xPos;
	m_rect.y = yPos;
		
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

void Brick::draw(SDL_Surface* dest) {
	SDL_BlitSurface(m_image, NULL, dest, &m_rect);
}
