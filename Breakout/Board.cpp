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

	//MAKE BRICKS (BARE ROT)
	for (int i = 3; i <= 750; i++)
	{	 
			 brickAr[counter] = { i, 3, 25, 97, black, 1 };
			 i += 98;
			 counter++;
	}

	for (int i = 3; i <= 750; i++)
	{
		brickAr[counter] = { i, 31, 25, 97, red, 1 };
		i += 98;
		counter++;
	}
	
	for (int i = 3; i <= 750; i++)
	{
		brickAr[counter] = { i, 59, 25, 97, yellow, 1 };
		i += 98;
		counter++;
	}

	for (int i = 3; i <= 750; i++)
	{
		brickAr[counter] = { i, 87, 25, 97, yellow, 1 };
		i += 98;
		counter++;
	}

	//lets see what the future holds
	/*for_each(begin(brickAr), end(brickAr), brickAr) {
		brickAr[counter] = { i, 3, 25, 97, red, 1 };
	});*/
	
	for (int i = 0; i < 32; i++)
	{
		brickAr[i].draw(dest);
	}
	/*Paddle paddle(350,577,15,100,red);
	paddle.draw(dest);*/

	


	
	

	
}

Board::~Board()
{
}

void Board::fillBricks()
{
	//vector<Brick> 
}
