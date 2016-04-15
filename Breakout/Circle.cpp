#include "Circle.h"

Circle::Circle()
{
	m_xPos = 0;
	m_yPos = 0;
	m_radius = 10;
	m_color = (255, 0, 0);
}

Circle::Circle(double xPos, double yPos, double rad, Uint32 color)
{
	m_xPos = xPos;
	m_yPos = yPos;
	m_radius = rad;
	m_color = color;
}

bool Circle::hit()
{
	return false;
}

void Circle::draw(SDL_Surface * dest)
{
	SDL_Rect rectDest;
	rectDest.x = m_xPos - (m_rect.w / 2);
	rectDest.y = m_yPos - (m_rect.h / 2);
	rectDest.w = m_rect.w;
	rectDest.h = m_rect.h;

	SDL_BlitSurface(m_image, &m_rect, dest, &rectDest);
}
