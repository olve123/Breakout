#include "Brick.h"
#include "Piece.h"

Brick::Brick()
{
}

Brick::Brick(int xPos, int yPos, int height, int length, uint32_t color, int hp)
	:Piece(xPos, yPos, height, length, color)
{
	m_hp = hp;
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
