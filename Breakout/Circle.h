#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"


class Circle : public Shape {
public:
	Circle();
	Circle(double xPos, double yPos, double radius, Uint32 color);
	

	double getRadius();
	double setRadius(double rad);
	
	bool hit() override;
	void draw(SDL_Surface* dest) override;

protected:
	double m_radius;
	
};

#endif // !CIRCLE_H
