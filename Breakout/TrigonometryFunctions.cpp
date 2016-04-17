#include "TrigonometryFunctions.h"

bool TrigonometryFunctions::overlap(const SDL_Rect& r1, const SDL_Rect& r2)
{
	return (
		(r1.x < (r2.x + r2.w)) &&
		((r1.x + r1.w) > r2.x) &&
		(r1.y < (r2.y + r2.h)) &&
		((r1.h + r1.y) > r2.y)
		);
		
}

bool TrigonometryFunctions::overlap(Circle& c, SDL_Rect& r)
{
	
	SDL_Point p = c.getSDL_CenterPoint();
	int radius = static_cast<int>(c.getRadius()); 
	if (SDL_PointInRect(&p, &expandRectange(r, radius, 0))) {
		return true;
	}
	if (SDL_PointInRect(&p, &expandRectange(r, 0, radius))) {
		return true;
	}
	SDL_Point upperLeft, upperRight, lowerLeft, lowerRight;
	upperLeft.x = r.x; upperLeft.y = r.y;
	upperRight.x = r.x + r.w; upperRight.y = r.y;
	lowerLeft.x = r.x; lowerLeft.y = r.y + r.h;
	lowerRight.x = r.x + r.w; lowerRight.y = r.y + r.h;

	if (distance(p, upperLeft) < radius) {
		return true;
	}
	if (distance(p, upperRight) < radius) {
		return true;
	}
	if (distance(p, lowerLeft) < radius) {
		return true;
	}
	if (distance(p, lowerRight) < radius) {
		return true;
	}

	return false;
}

int TrigonometryFunctions::distance(SDL_Point & p1, SDL_Point & p2)
{
	double d = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return static_cast<int>(d);
	
}


SDL_Rect TrigonometryFunctions::expandRectange(SDL_Rect& r, int xDiff, int yDiff)
{
	SDL_Rect ret;
	ret.x = r.x - xDiff;
	ret.w = r.w + (2 * xDiff);
	ret.y = r.y - yDiff;
	ret.h = r.h + (2 * yDiff);
	if (ret.w < 0)
		ret.w = 0;
	if (ret.h < 0)
		ret.h = 0;

	return ret;
}
