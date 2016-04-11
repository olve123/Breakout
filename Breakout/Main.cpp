// ConsoleApplication4.cpp : Defines the entry point for the console application.
//
#include "SDL.h"
#include <iostream>
#include "Piece.h"

#define window_width 800
#define window_height 600
#define fps 60

using namespace std;

//experiment
class Brick {

};

class Board {
public:
	Board(SDL_Renderer* renderer);



};


//--------------------------------------------------------------//


//SET FRAMERATE TO 60FPS
void cap_framerate(Uint32 starting_tick) {
	if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
		SDL_Delay(1000 / fps - (SDL_GetTicks() - starting_tick));
	}
}

class block {
private: 
	SDL_Surface *image;
	SDL_Rect rect; 

	int origin_x, origin_y;
public: 
	block(Uint32 color, int x, int y, int w = 50, int h = 20) {
		image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
		SDL_FillRect(image, NULL, color);

		rect = image->clip_rect;

		origin_x = rect.w / 2;
		origin_y = rect.h / 2;

		rect.x = x - origin_x;
		rect.y = y - origin_y;

	}
	void update() {
		//can be overridden!
	}

	void draw(SDL_Surface *destination) {
		SDL_BlitSurface(image, NULL, destination, &rect);
	}

};

class paddle {
private:
	SDL_Surface *image;
	SDL_Rect rect;

	int origin_x, origin_y;

public:
	paddle(Uint32 color, int x, int y, int w = 200, int h = 20) {
		image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
		SDL_FillRect(image, NULL, color);

		rect = image->clip_rect;

		origin_x = rect.w / 2;
		origin_y = rect.h / 2;

		rect.x = x - origin_x;
		rect.y = y - origin_y;
	}
	void draw(SDL_Surface *destination) {
		SDL_BlitSurface(image, NULL, destination, &rect);
	}
};


//////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
	//init sdl
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = NULL;
	Uint8 keystate;
	//window properties
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

	//COLORS
	Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255);
	Uint32 black = SDL_MapRGB(screen->format, 0, 0, 0);
	Uint32 red = SDL_MapRGB(screen->format, 255, 0, 0);
	Uint32 blue = SDL_MapRGB(screen->format, 0, 0, 255);

	//BACKGROUNDCOLOR
	SDL_FillRect(screen, NULL, white);
	

	//TURN ON/OFF BORDERS TRUE = BORDERS
	SDL_SetWindowBordered(window, SDL_TRUE);

	//INIT 
	Uint32 starting_tick;
	

	//DRAWING RECTANGLES
	block object1(red, 30, 20);
	object1.draw(screen);

	block object2(black, 82, 20);
	object2.draw(screen);

	block object3(red, 134, 20);
	object3.draw(screen);

	block object4(black, 186, 20);
	object4.draw(screen);

	block object5(red, 238, 20);
	object5.draw(screen);

	block object6(black, 290, 20);
	object6.draw(screen);

	block object7(red, 342, 20);
	object7.draw(screen);

	paddle paddle(blue, 150, 580);
	paddle.draw(screen);

	
	SDL_Event event;
	bool running = true;

	//GAMELOOP
	while (running) {
		
		//keystate = SDL_GetKeyboardState(NULL);
		//if (keystate[SDLK_LEFT]) {
		//	paddle. -= 2;
		//}
		SDL_UpdateWindowSurface(window);
		starting_tick = SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			
			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}
		}
		//FRAMERATELOCK
		cap_framerate(starting_tick);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;



}

