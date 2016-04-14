#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"


class Square : public Shape {
public:
	Square();
	Square(double xPos, double yPos, Uint32 color);
	Square(double xPos, double yPos , double height, double length, Uint32 color);
	

	double getHeight();
	double getLength();

	void setHeight(double height);
	void setLength(double length);
	void initSize(double m_height, double m_length);

	bool hit() override;
	void draw(SDL_Surface* dest) override;

protected:
	double m_height;
	double m_length;
	SDL_Rect m_rect;
};

#endif // !SQUARE_H
