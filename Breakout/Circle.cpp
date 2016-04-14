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
