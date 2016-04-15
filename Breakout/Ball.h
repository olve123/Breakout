#ifndef BALL_H
#define BALL_H

#include "Common.h"
#include "Circle.h"
#include "Paddle.h"
//#include "MyTexture.h"

class Ball : public Circle
{
public:
	Ball();
	Ball(double xPos, double yPos, double radius, Uint32 color);
	//~Ball();

	//void init(Paddle& paddle); // Places the ball in the correct position
	//bool update(Paddle& paddle, Board& board);
	//void drawBall();
	void updateBallPosition();
	
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;
	static const int DOT_VEL = 10;

	//void handleEvent(SDL_Event& e);
	//void move();
	//void render();
	//MyTexture gDotTexture;

private: 
	int const m_speed = 10;
	double m_xDiff;
	double m_yDiff;
	double m_radius;
	
};

#endif // !BALL_H