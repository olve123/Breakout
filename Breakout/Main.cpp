// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "SDL.h"
#include <iostream>

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

class Sprite {
private: 
	SDL_Surface *image;
	SDL_Rect rect; 

	int origin_x, origin_y;
public: 
	Sprite(Uint32 color, int x, int y, int w = 50, int h = 20) {
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


int main(int argc, char *argv[]) {
	//init sdl
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = NULL;

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

	//BACKGROUNDCOLOR
	SDL_FillRect(screen, NULL, white);
	

	//TURN ON/OFF BORDERS TRUE = BORDERS
	SDL_SetWindowBordered(window, SDL_TRUE);

	//INIT 
	Uint32 starting_tick;

	
	//DRAWING RECTANGLES
	Sprite object1(red, 30, 20);
	object1.draw(screen);

	Sprite object2(black, 82, 20);
	object2.draw(screen);



	//SDL_Rect rect;
	//rect.x = 10;
	//rect.y = 10;
	//rect.w = 50;
	//rect.h = 20;
	//SDL_FillRect(screen, &rect, black);

	
	//rect.x = 62;
	//SDL_FillRect(screen, &rect, red);
	//UPDATE
	SDL_UpdateWindowSurface(window);


	SDL_Event event;
	bool running = true;

	//GAMELOOP
	while (running) {

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

