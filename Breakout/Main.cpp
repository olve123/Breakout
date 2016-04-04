// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "SDL.h"
#include <iostream>

#define window_width 800
#define window_height 600

//COLORS
#define fps 60

using namespace std;

//SET FRAMERATE TO 60FPS
void cap_framerate(Uint32 starting_tick) {
	if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
		SDL_Delay(1000 / fps - (SDL_GetTicks() - starting_tick));
	}
}


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

	//BACKGROUNDCOLOR
	SDL_FillRect(screen, NULL, white);
	//UPDATE
	SDL_UpdateWindowSurface(window);

	//TURN ON/OFF BORDERS TRUE = BORDERS
	SDL_SetWindowBordered(window, SDL_TRUE);

	//INIT 
	Uint32 starting_tick;



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

