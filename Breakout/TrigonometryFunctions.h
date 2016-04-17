#ifndef TRIGONOMETRYFUNCTIONS_H
#define TRIGONOMETRYFUNCTIONS_H

#include <SDL.h>
#include "Circle.h"
#include <math.h>

class TrigonometryFunctions {
public:

	// Check if rectangle r1 overlaps rectangle r2
	static bool overlap(const SDL_Rect& r1, const SDL_Rect& r2);

	// Check if circle overlaps a rectangle
	static bool overlap( Circle& c, SDL_Rect& r);

	// Calculate a distance between two points
	static int distance(SDL_Point& p1, SDL_Point& p2);

	// Create a new rectangle based on input rectanlge and expand with xDiff horizontally and yDiff vertically
	static SDL_Rect expandRectange(SDL_Rect& r, int xDiff, int yDiff);

private:

};

#endif // !TRIGONOMETRYFUNCTIONS_H
