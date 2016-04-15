#include "Ball.h"
#include <iostream>

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
//
//void Ball::handleEvent(SDL_Event & e)
//{
//	//If a key was pressed
//	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
//	{
//		//Adjust the velocity
//		switch (e.key.keysym.sym)
//		{
//		case SDLK_UP: mVelY -= DOT_VEL; break;
//		case SDLK_DOWN: mVelY += DOT_VEL; break;
//		case SDLK_LEFT: mVelX -= DOT_VEL; break;
//		case SDLK_RIGHT: mVelX += DOT_VEL; break;
//		}
//	}
//	//If a key was released
//	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
//	{
//		//Adjust the velocity
//		switch (e.key.keysym.sym)
//		{
//		case SDLK_UP: mVelY += DOT_VEL; break;
//		case SDLK_DOWN: mVelY -= DOT_VEL; break;
//		case SDLK_LEFT: mVelX += DOT_VEL; break;
//		case SDLK_RIGHT: mVelX -= DOT_VEL; break;
//		}
//	}
//}
//
//void Ball::move()
//{
//	//Move the dot left or right
//	m_xPos += mVelX;
//
//	//If the dot went too far to the left or right
//	if ((m_xPos < 0) || (m_xPos + DOT_WIDTH > SCREEN_WIDTH))
//	{
//		//Move back
//		m_xPos -= mVelX;
//	}
//
//	//Move the dot up or down
//	m_yPos += mVelY;
//
//	//If the dot went too far up or down
//	if ((m_yPos < 0) || (m_yPos + DOT_HEIGHT > SCREEN_HEIGHT))
//	{
//		//Move back
//		m_yPos -= mVelY;
//	}
//}
//
//void Ball::render()
//{
//	gDotTexture.render(m_xPos, m_yPos);
//}
