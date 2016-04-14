#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(int xPos, int yPos, uint32_t color, double radius)
	:Circle(xPos, yPos, color)
{
	m_radius = radius;
}


//
//bool Ball::update(Paddle & paddle, Board & board)
//{
//	return false;
//}

void Ball::updateBallPosition()
{
	m_xPos += m_xDiff;
	m_yPos += m_yDiff;
}
