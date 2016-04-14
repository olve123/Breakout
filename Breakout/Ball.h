#ifndef BALL_H
#define BALL_H

#include "Circle.h"

class Ball : public Circle
{
public:
	Ball();
	Ball(double xPos, double yPos, uint32_t color, double radius);
	//~Ball();

	void init(Paddle& paddle); // Places the ball in the correct position
	
	//bool update(Paddle& paddle, Board& board);
	void drawBall();
	

	void updateBallPosition();

	
private: 
	int const speed ;
	double m_xDiff;
	double m_yDiff;
	double m_radius;
	
};

#endif // !BALL_H