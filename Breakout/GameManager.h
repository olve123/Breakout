#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
/*
*	GAMEMANAGER
*
*/
#include <string>
#include "SDL.h"
#include "Paddle.h"
#include "Ball.h"
#include <iostream>
#include "Common.h"
#include "Bricks.h"
using namespace std;
class GameManager {
	
public:
	GameManager();
	void init();
	void gameOver();
	void pause();
	void menu();
	void start();
	void cap_framerate(Uint32 starting_tick);

private:
	SDL_Window* window;
	SDL_Surface* screen;
	SDL_Surface* image;
	SDL_Rect rect;
	bool running;
	Uint32 starting_tick;
};


#endif// !GAMEMANAGER_H