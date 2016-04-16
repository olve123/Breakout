#ifndef TRIGONOMETRYFUNCTIONS_H
#define TRIGONOMETRYFUNCTIONS_H

#include <SDL.h>
#include "Circle.h"
class TrigonometryFunctions {
public:
	// Check if point p is inside rectangle r
	//bool inside(&SDL_Point p, &SDL_Rect r);
	
	//!!!  SDL_PointInRect(const SDL_Point, const SDL_Rect);
	
	// Check if rectangle r1 overlaps rectangle r2
	static bool overlap(const SDL_Rect& r1, const SDL_Rect& r2);
	// Check if circle overlaps a rectangle
	static bool overlap( Circle& c, SDL_Rect& r);
	// Calculate a distance between two points
	int distance(SDL_Point& p1, SDL_Point& p2);
	// Create a new rectangle based on input rectanlge and expand with xDiff horizontally and yDiff vertically
	static SDL_Rect expandRectange(SDL_Rect& r, int xDiff, int yDiff);

private:

};

#endif // !TRIGONOMETRYFUNCTIONS_H
