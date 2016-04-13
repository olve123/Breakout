#ifndef BALL_H
#define BALL_H

#include "Piece.h"

class Ball : public Piece
{
public:
	Ball();
	Ball(int xPos, int yPos, uint32_t color, double radius);
	~Ball();

	void init(); // Places the ball in the correct position
	
	//bool update(Paddle& paddle, Board& board);
	//void drawBall();
	
	double getRadius() const;
	void setRadius(double r);

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

private: 
	double m_xDir;
	double m_yDir;
	double m_radius;
	
	void x_bounce();
	void yBounce();
};

#endif // !BALL_H