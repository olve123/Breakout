#ifndef BALL_H
#define BALL_H

#include "Piece.h"

class Ball : public Piece
{
public:
	Ball();
	Ball(int xPos, int yPos, uint32_t color, double radius);
	~Ball();
	
	double getRadius() const;
	void setRadius(double r);

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

private: 
	double m_radius;
};

#endif // !BALL_H