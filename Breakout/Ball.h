//BALL.h creates a ball and collission detection methods
#ifndef BALL_H
#define BALL_H

#include "Common.h"
#include "Circle.h"
#include "Paddle.h"
#include "TrigonometryFunctions.h"

class Ball : public Circle
{
public:
	Ball();
	Ball(double xPos, double yPos, double radius, Uint32 color);
	void setXDiff(double xDiff);
	void setYDiff(double yDiff);

	double getXDiff();
	double getYDiff();
	
	void updateBallPosition();
	void moveBall();

	// Check collision detection methods
	bool checkPaddleHit(SDL_Rect& paddle, Circle& ball);
	bool checkWalls();
	
	bool checkGameOver();

private: 
	double m_xDiff;
	double m_yDiff = -5;
	
};

#endif // !BALL_H