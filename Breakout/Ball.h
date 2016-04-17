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
	//~Ball();

	//void init(Paddle& paddle); // Places the ball in the correct position
	//bool update(Paddle& paddle, Board& board);
	//void drawBall();
	void setXDiff(double xDiff);
	void setYDiff(double yDiff);

	double getXDiff();
	double getYDiff();
	
	void updateBallPosition();
	void moveBall();
	
	bool checkPaddleHit(SDL_Rect& paddle, Circle& ball);
	bool checkWalls();
private: 
	double m_xDiff;
	double m_yDiff = -5;
	//GameManager gm();
	
};

#endif // !BALL_H