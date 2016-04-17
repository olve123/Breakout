#include "Shape.h"


Shape::~Shape()
{
}

double Shape::getX() const
{
	return m_xPos;
}

double Shape::getY() const
{
	return m_yPos;
}
Uint32 Shape::getColor() const
{
	return m_color;
}


void Shape::setX(double pos)
{
	m_xPos = pos;
}

void Shape::setY(double pos)
{
	m_yPos = pos;
}


void Shape::setColor(Uint32 color)
{
	m_color = color;
}

void Shape::initPos(double xPos, double yPos) {
	setX(xPos);
	setY(yPos);
}

SDL_Rect Shape::getRect()
{
	return m_rect;
}





