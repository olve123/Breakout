#ifndef SHAPE_H
#define SHAPE_H
/*
* Abstract class to be inherited from by Brick, Ball and Paddle classes
*/
#include "SDL.h"

class Shape {
public:
	virtual ~Shape();

	double getX() const;
	double getY() const;
	Uint32 getColor() const;

	void setX(double pos);
	void setY(double pos);
	void setColor(Uint32 color);
	void initPos(double m_xPos, double m_yPos);


	virtual bool hit() = 0;
	virtual void draw(SDL_Surface* dest) = 0;

protected:
	double m_xPos;
	double m_yPos;
	Uint32 m_color;
	SDL_Surface *m_image;
	
};

#endif // !SHAPE_H
