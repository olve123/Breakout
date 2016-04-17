#include "GameManager.h"
#include "Paddle.h"
#include "Ball.h"
#include "Board.h"
#include <iostream>
#include "Common.h"

GameManager::GameManager()
{
}

void GameManager::init()
{
	running = true;
	//INITIATE SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	//WINDOW PROPERTIES
	window = SDL_CreateWindow(
		"BREAKOUT",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_RESIZABLE
		);

	//ERROR HANDLING
	if (window == NULL) {
		cout << "there was an error initializing the window!" << endl
			<< SDL_GetError() << endl;
	}

	//ADD SCREEN TO WINDOW
	screen = SDL_GetWindowSurface(window);

	//TURN ON/OFF BORDERS TRUE = BORDERS
	SDL_SetWindowBordered(window, SDL_TRUE);

}


void GameManager::gameOver()
{
	//gameover loop
	//draw bilde av gameoverscreen
	//trykk r for restart 
	//q for quit

	bool gameover = true;
	SDL_Event gameOverEvent;
	image = SDL_LoadBMP("gameover.bmp");
	rect.h = SCREEN_HEIGHT;
	rect.w = SCREEN_WIDTH;
	rect.x = 0;
	rect.y = 0;
	while (gameover) {
		//draw gameover
		SDL_BlitSurface(image, NULL, screen, NULL);
		SDL_UpdateWindowSurface(window);
		while (SDL_PollEvent(&gameOverEvent)) {
			
			switch (gameOverEvent.key.keysym.sym) {
			
			case SDLK_SPACE:
				gameover = false;
				break;

			case SDLK_q:
				running = 0;
				break;
			}

			if (gameOverEvent.type == SDL_QUIT) {
				running = false;
				break;
			}

			if (!running) {
				SDL_DestroyWindow(window);
				SDL_Quit();
			}
		}
	}
}


void GameManager::pause()
{
	bool pause = true;
	SDL_Event pauseEvent;
	while (pause) {
		//draw pause
		while (SDL_PollEvent(&pauseEvent)) {
			switch (pauseEvent.key.keysym.sym) {
			
			case SDLK_SPACE:
				pause = false;
				break;
			
			case SDLK_q:
				running = 0;
				break;
			}
			
			if (pauseEvent.type == SDL_QUIT) {
				running = false;
				break;
			}
			
			if (!running) {
				SDL_DestroyWindow(window);
				SDL_Quit();
			}
		}
	}
}

void GameManager::menu()
{
	image = SDL_LoadBMP("menu.bmp");
	rect.h = SCREEN_HEIGHT;
	rect.w = SCREEN_WIDTH;
	rect.x = 0;
	rect.y = 0;

	bool menu = true;
	SDL_Event menuEvent;
	while (menu) {
		//draw menu "PRESS S TO START"
		SDL_BlitSurface(image,NULL,screen,NULL);
		SDL_UpdateWindowSurface(window);
		while (SDL_PollEvent(&menuEvent)) {
			switch (menuEvent.key.keysym.sym) {
			
			case SDLK_s:
				menu = false;
				break;
		
			case SDLK_q:
				running = 0;
				break;
			}
		}

		if (menuEvent.type == SDL_QUIT) {
			running = false;
			break;
		}
	}
	
	if (!running) {
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
}

void GameManager::start()
{
	SDL_Event event;
	//Create Paddle
	Paddle paddle(350, 577, 15, 100, (192153131));
	//Create Ball
	Ball ball(400, 550, 20, (192153131));
	
	// MAIN GAMELOOP	
	while (running) {
		//fps
		starting_tick = SDL_GetTicks();
		//fill screen with a white background
		SDL_FillRect(screen, NULL, 0x000000);
		//new board object
		Board board(screen);
		//draw paddle
		paddle.draw(screen);
		ball.checkPaddleHit(paddle.getRect(), ball);
		ball.checkWalls();
		ball.moveBall();
		ball.draw(screen);

		while (SDL_PollEvent(&event)) {
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
			
			case SDLK_p:
				pause();
			}

			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}
		}
		SDL_UpdateWindowSurface(window);
		SDL_FreeSurface(screen);

		//FRAMERATELOCK // AND FOR GOD SAKE DELETE MEMORY LOL
		cap_framerate(starting_tick);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	

}

void GameManager::cap_framerate(Uint32 starting_tick)
{
	if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
		SDL_Delay(1000 / fps - (SDL_GetTicks() - starting_tick));
	}
}

