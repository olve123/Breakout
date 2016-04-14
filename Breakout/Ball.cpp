#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(int xPos, int yPos, uint32_t color, double radius)
	:Piece(xPos, yPos, color)
{
	m_radius = radius;
}

Ball::~Ball()
{
}

bool Ball::update(Paddle & paddle, Board & board)
{
	return false;
}