// ConsoleApplication4.cpp : Defines the entry point for the console application.
//
#include "SDL.h"
#include <iostream>
#include "Piece.h"
#include <vector>
#include "Brick.h"
#include "Board.h"
#include "Paddle.h"

#define window_width 800
#define window_height 600
#define fps 60

using namespace std;

//SET FRAMERATE TO 60FPS
void cap_framerate(Uint32 starting_tick) {
	if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
		SDL_Delay(1000 / fps - (SDL_GetTicks() - starting_tick));
	}
}
//OLD BRICK
//class Block {
//private: 
//	SDL_Surface *image;
//	SDL_Rect rect; 
//public: 
//	Block(int x, int y, int h, int w, Uint32 color) {
//		image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
//		SDL_FillRect(image, NULL, color);
//		rect.x = x;
//		rect.y = y;
//
//	}
//	void update() {
//		//can be overridden!
//	}
//
//	void draw(SDL_Surface *destination) {
//		SDL_BlitSurface(image, NULL, destination, &rect);
//	}
//
//};


//class paddle {
//private:
//	SDL_Surface *image;
//	SDL_Rect rect;
//
//	int origin_x, origin_y;
//
//public:
//	paddle(Uint32 color, int x, int y, int w = 200, int h = 20) {
//		image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
//		SDL_FillRect(image, NULL, color);
//
//		rect = image->clip_rect;
//
//		origin_x = rect.w / 2;
//		origin_y = rect.h / 2;
//
//		rect.x = x - origin_x;
//		rect.y = y - origin_y;
//	}
//	void draw(SDL_Surface *destination) {
//		SDL_BlitSurface(image, NULL, destination, &rect);
//	}
//};

//OLD PADDLE AND BRICK OVER ^^

//////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
	//RUNNING
	bool running = true;
	//INITIATE SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = NULL;
	//WINDOW PROPERTIES
	window = SDL_CreateWindow(
		"BREAKOUT",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		window_width,
		window_height,
		SDL_WINDOW_RESIZABLE
		);
	//ERROR HANDLING
	if (window == NULL) {
		cout << "there was an error initializing the window!" << endl
			<< SDL_GetError() << endl;
	}

	//ADD SCREEN TO WINDOW
	SDL_Surface *screen = SDL_GetWindowSurface(window);

	//TURN ON/OFF BORDERS TRUE = BORDERS
	SDL_SetWindowBordered(window, SDL_TRUE);

	//INIT TICKS
	Uint32 starting_tick;
	
	//CREATE BOARD
	Board board(screen);

	SDL_Event event;


	Paddle paddle(350, 577, 15, 100, (192153131));
	Ball ball();

	//GAMELOOP
	while (running) {
		starting_tick = SDL_GetTicks();
		SDL_FillRect(screen, NULL, 0x000000);
		paddle.draw(screen);
		while (SDL_PollEvent(&event)) {
			
			//paddle.draw(screen);
			switch (event.key.keysym.sym) {
			
			case SDLK_q: 
				running = 0;
			case SDLK_LEFT:
				paddle.moveLeft(15);
				paddle.draw(screen);
				break;

			case SDLK_RIGHT:
				paddle.moveRight(15);
				paddle.draw(screen);
				break;
			}

			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}
		}
		ball.updateBallPosition();

		// check for collision with objects
		if (paddle.hit(ball.getX(), ball.getY() + ball.getRadius())) {
			ball.setYDiff(-ball.getYDiff);
			ball.setY(paddle.getY() - ball.getRadius());
		}
		else if (paddle.miss(ball.getX(), ball.getY() + ball.getRadius())) {
			// do some miss action
		}
		else if ((ball.getX() - ball.getRadius()) <= xLeftWall) {
			ball.setXDiff(-ball.getXDiff());
			ball.setX(xLeftWall + ball.getRadius());
		}
		
		SDL_UpdateWindowSurface(window);
		//FRAMERATELOCK // AND FOR GOD SAKE DELETE MEMORY LOL
		cap_framerate(starting_tick);
	}
	
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;



}

