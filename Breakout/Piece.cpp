#include "Piece.h"
#include <iostream>

void Piece::initSize(int height, int length)
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
void Piece::initPos(int xPos, int yPos) {
	setX_Pos(xPos);
	setY_Pos(yPos);
}

void Piece::setX_Pos(int pos)
{
	m_xPos = pos;
}

void Piece::setY_Pos(int pos)
{
	m_yPos = pos;
}

void Piece::setHeight(int height)
{
	m_height = height;
}

void Piece::setLength(int length)
{
	m_length = length;
}

void Piece::setColor(uint32_t color)
{
}

void Piece::setColor(uint32_t color)
{
	m_color = color;
}

Piece::Piece()
{
}

Piece::Piece(int xPos, int yPos, uint32_t color)
{
	initPos(xPos, yPos);
	setColor(color);
}

Piece::Piece(int xPos, int yPos, int height, int length, uint32_t color = (0,0,0))
{
	initPos(xPos, yPos);
	initSize(height, length);
	setColor(color);
}

Piece::~Piece()
{
}

int Piece::getX_Pos()
{
	return m_xPos;
}

int Piece::getY_Pos()
{
	return m_yPos;
}

int Piece::getHeight()
{
	return m_height;
}

int Piece::getLength()
{
	return m_length;
}

uint32_t Piece::getColor()
{
	return uint32_t(m_color);
}
