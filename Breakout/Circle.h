#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"


class Circle : public Shape {
public:
	Circle();
	Circle(double xPos, double yPos, double radius, Uint32 color);
	

	double getRadius();
	//double setRadius(double rad);
	SDL_Point getSDL_CenterPoint();
	bool hit() override;
	void draw(SDL_Surface* dest) override;

protected:
	//SDL_Point m_centerPoint;
	double m_radius;
	
};

#endif // !CIRCLE_H
