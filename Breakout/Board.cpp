#include "Board.h"
#include "Brick.h"



Board::Board()
{
}

Board::Board(SDL_Surface* dest)
{
	Uint32 white = SDL_MapRGB(dest->format, 255, 255, 255);
	Uint32 black = SDL_MapRGB(dest->format, 0, 0, 0);
	Uint32 red = SDL_MapRGB(dest->format, 255, 0, 0);
	Uint32 green = SDL_MapRGB(dest->format, 0, 255, 0);
	Uint32 blue = SDL_MapRGB(dest->format, 0, 0, 255);
	Uint32 yellow = SDL_MapRGB(dest->format, 255, 255, 0);
	Uint32 cyan = SDL_MapRGB(dest->format, 0, 255, 255);
	Uint32 pink = SDL_MapRGB(dest->format, 255, 0, 255);
	Uint32 gray = SDL_MapRGB(dest->format, 192, 192, 192);

	//FILL BOARD WITH WHITE, WHEN BOARD IS CALLED. 
	SDL_FillRect(dest, NULL, gray);
	
	
	//MAKE BRICKS
	Brick brick(3, 3, 25, 100, red, 1);
	brick.draw(dest);

	Brick brick2(106, 3, 25, 100, cyan, 1);
	brick2.draw(dest);
}

Board::~Board()
{
}
