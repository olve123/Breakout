#include "Ball.h"
#include <iostream>
#include "GameManager.h"

Ball::Ball()
{
	m_xPos = 0;
	m_yPos = 0;
	m_image = SDL_LoadBMP("dot.bmp");
	m_rect.x = 0;
	m_rect.y = 0;
	m_rect.w = m_image->w;
	m_rect.h = m_image->h;
}

Ball::Ball(double xPos, double yPos, double radius, Uint32 color)
	:Circle(xPos, yPos, radius, color)
{
	m_image = SDL_LoadBMP("dot.bmp");
	m_rect.x = 0;
	m_rect.y = 0;
	m_rect.w = m_image->w;
	m_rect.h = m_image->h;
	//m_centerPoint.x = m_rect.x + (m_rect.w / 2);
	//m_centerPoint.y = m_rect.y +  (m_rect.h / 2);
}

void Ball::setXDiff(double xDiff)
{
	m_xDiff = xDiff;
}

void Ball::setYDiff(double yDiff)
{
	m_yDiff = yDiff;
}

double Ball::getXDiff()
{
	return m_xDiff;
}

double Ball::getYDiff()
{
	return m_yDiff;
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
void Ball::moveBall()
{
		m_xPos += m_xDiff;
		m_yPos += m_yDiff;

}


bool Ball::checkPaddleHit(SDL_Rect& paddle, Circle& ball)
{
	if (TrigonometryFunctions::overlap(ball, paddle)) {
		double xCenter = paddle.x + (paddle.w / 2);
		double xHit = ball.getX();
		m_xDiff = ((xHit - xCenter) / paddle.h) * (m_yDiff/2);
		m_yDiff = -m_yDiff;
		ball.setY(paddle.y - ball.getRadius());
		return true;
	}
	return false;
}

bool Ball::checkWalls()
{
	if (m_yPos < m_radius) {
		m_yDiff = -m_yDiff;
		m_yPos = m_radius;
		return true;
	}
	else if (m_xPos < 0) {
		m_xDiff = -m_xDiff;
		m_xPos = m_radius;
		return true;
	}
	else if (m_xPos > (SCREEN_WIDTH - m_radius)) {
		m_xDiff = -m_xDiff;
		m_xPos = SCREEN_WIDTH - m_radius;
		return true;
	}
	else if (m_yPos > SCREEN_HEIGHT + m_radius) {
		//send til gamemanager->gameover
	}
	return false;	
}
