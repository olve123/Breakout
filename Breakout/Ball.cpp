#include "Ball.h"



Ball::Ball()
{
}

Ball::Ball(int xPos, int yPos, uint32_t color, double radius)
	:Piece(xPos, yPos,color)
{
	setRadius(radius);
}



Ball::~Ball()
{
}

double Ball::getRadius()
{
	return m_radius;
}

void Ball::setRadius(double r)
{
	m_radius = r;
}
