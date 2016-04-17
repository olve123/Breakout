#ifndef BOARD_H
#define BOARD_H

/*
*	BOARD
*	
*/
#include "SDL.h"
#include <string>
using namespace std;

class Board {
public: 
	 Board();
	 Board(SDL_Surface* dest);
	 ~Board();

	 
	 void fillBricks();

};


#endif//!BOARD_H