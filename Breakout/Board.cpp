#include "Board.h"
#include "Brick.h"
#include "Paddle.h"
#include <vector>
#include <algorithm>


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
	SDL_FillRect(dest, NULL, white);
	
	//Brick bricks[2];
	int counter = 0;
	//make brick array 
	Brick brickAr[50];
//#define OLDBRICKS
#ifdef OLDBRICKS


	//MAKE BRICKS (BARE ROT)
	for (int i = 3; i <= 750; i++)
	{	 
			 brickAr[counter] = { static_cast<double>(i), 3.0, 25, 97, black, 1 };
			 i += 98;
			 counter++;
	}

	for (int i = 3; i <= 750; i++)
	{
		brickAr[counter] = { static_cast<double>(i), 31.0, 25, 97, red, 1 };
		i += 98;
		counter++;
	}
	
	for (int i = 3; i <= 750; i++)
	{
		brickAr[counter] = { static_cast<double>(i), 59.0, 25, 97, yellow, 1 };
		i += 98;
		counter++;
	}

	for (int i = 3; i <= 750; i++)
	{
		brickAr[counter] = { static_cast<double>(i), 87.0, 25, 97, yellow, 1 };
		i += 98;
		counter++;
	}
	
	for (int i = 0; i < 32; i++)
	{
		brickAr[i].draw(dest);
	}
#else
	
#endif // OLDBRICKS	

}

Board::~Board()
{
}

void Board::fillBricks()
{
	//vector<Brick> 
}
