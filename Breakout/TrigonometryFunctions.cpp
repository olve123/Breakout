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
	
	const SDL_Point p = c.getSDL_CenterPoint();
	int radius = static_cast<int>(c.getRadius()); 
	const SDL_Rect rectAddX = expandRectange(r, radius, 0);
	const SDL_Rect rectAddY = expandRectange(r, 0, radius);

	return (
		SDL_PointInRect(&p, &rectAddX) ||
		SDL_PointInRect(&p, &rectAddY) 
		);
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
