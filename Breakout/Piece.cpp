#include "Piece.h"
#include <iostream>

void Piece::initSize(double height, double length)
{
	setHeight(height);
	setLength(length);
}
void Piece::PrintStats() const
{
	cout 
		<< "x = " << m_xPos
		<< "\t y= " << m_yPos 
		<< "\t height : " << m_height 
		<< "\t length : " << m_length 
		<< "\t color : " << m_color 
		<< endl;
}
void Piece::draw(SDL_Surface * dest)
{
}
void Piece::initPos(double xPos, double yPos) {
	setX(xPos);
	setY(yPos);
}

void Piece::setX(double pos)
{
	m_xPos = pos;
}

void Piece::setY(double pos)
{
	m_yPos = pos;
}

void Piece::setHeight(double height)
{
	m_height = height;
}

void Piece::setLength(double length)
{
	m_length = length;
}

void Piece::setColor(Uint32 color)
{
	m_color = color;
}

Piece::Piece()
{
}

Piece::Piece(double xPos, double yPos, Uint32 color)
{
	initPos(xPos, yPos);
	setColor(color);
}

Piece::Piece(double xPos, double yPos, double height, double length, Uint32 color = (0,0,0))
{
	initPos(xPos, yPos);
	initSize(height, length);
	setColor(color);
}

Piece::~Piece()
{
}

double Piece::getX()
{
	return m_xPos;
}

double Piece::getY()
{
	return m_yPos;
}

double Piece::getHeight()
{
	return m_height;
}

double Piece::getLength()
{
	return m_length;
}

Uint32 Piece::getColor()
{
	return m_color;
}
