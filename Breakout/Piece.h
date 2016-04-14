#ifndef PIECE_H
#define PIECE_H
/*
* Intented to be inherited from by Brick, Ball and Paddle classes
*/
#include <string>
#include "SDL.h"
using namespace std;

class Piece {
public:
	Piece();
	Piece(double xPos, double yPos, Uint32 color);
	Piece(double xPos, double yPos , double height, double length, Uint32 color);
	~Piece();

	double getX();
	double getY();
	double getHeight();
	double getLength();
	Uint32 getColor();

	void setX(double pos);
	void setY(double pos);
	void setHeight(double height);
	void setLength(double length);
	void setColor(Uint32 color);

	void PrintStats() const;
	void initPos(double m_xPos, double m_yPos);
	void initSize(double m_height, double m_length);

	virtual void draw(SDL_Surface* dest);

protected:
	double m_xPos;
	double m_yPos;
	double m_height;
	double m_length;
	Uint32 m_color;
};

#endif // !PIECE_H
