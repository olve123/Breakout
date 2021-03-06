#include "Square.h"


Square::Square()
{
}

Square::Square(double xPos, double yPos, Uint32 color)
{
	initPos(xPos, yPos);
	setColor(color);
}

Square::Square(double xPos, double yPos, int height, int length, Uint32 color = (0, 0, 0))
{
	m_image = SDL_CreateRGBSurface(0, length, height, 32, 0, 0, 0, 0);
	initPos(xPos, yPos);
	initSize(height, length);
	setColor(color);
}



int Square::getHeight()
{
	return m_height;
}

int Square::getLength()
{
	return m_length;
}


void Square::setHeight(int height)
{
	m_height = height;
}

void Square::setLength(int length)
{
	m_length = length;
}

void Square::initSize(int height, int length)
{
	m_height = height;
	m_length = length;
}

bool Square::hit()
{
	// something to check for collision here
	return false;
}

void Square::draw(SDL_Surface * dest)
{
	SDL_BlitSurface(m_image, NULL, dest, &m_rect);
}






//void Square::PrintStats() const
//{
//	cout 
//		<< "x = " << m_xPos
//		<< "\t y= " << m_yPos 
//		<< "\t height : " << m_height 
//		<< "\t length : " << m_length 
//		<< "\t color : " << m_color 
//		<< endl;
//}
