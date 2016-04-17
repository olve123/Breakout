#ifndef BRICKS_H
#define BRICKS_H

#include <vector>
#include "Brick.h"
#include <SDL.h>
#include "Common.h" 
#include "TrigonometryFunctions.h"
#include <iostream>
#include "Ball.h"

class Bricks {
public:
	Bricks() {

	}
 
	void createBricks();
	void drawBricks(SDL_Surface* dest);
	void checkBricks(Ball& ball);


private:
	
	std::vector<Brick> brickAr;
};
#endif // !BRICKS_H
