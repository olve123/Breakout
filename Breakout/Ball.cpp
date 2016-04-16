#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(double xPos, double yPos, double radius, Uint32 color)
	:Circle(xPos, yPos, radius, color)
{
	
}

void Ball::init(Paddle & paddle)
{
}

void Ball::drawBall()
{
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
