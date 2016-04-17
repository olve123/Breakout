#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"


class Square : public Shape {
public:
	Square();
	Square(double xPos, double yPos, Uint32 color);
	Square(double xPos, double yPos , int height, int length, Uint32 color);
	

	int getHeight();
	int getLength();

	void setHeight(int height);
	void setLength(int length);
	void initSize(int m_height, int m_length);

	bool hit() override;
	void draw(SDL_Surface* dest) override;

protected:
	int m_height;
	int m_length;
	
};

#endif // !SQUARE_H
