#include "GameManager.h"
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
		cout << "There was an error initializing the window!" << endl
			<< SDL_GetError() << endl;
	}

	//ADD SCREEN TO WINDOW
	screen = SDL_GetWindowSurface(window);

	//TURN ON/OFF BORDERS TRUE = BORDERS
	SDL_SetWindowBordered(window, SDL_TRUE);

}


void GameManager::gameOver()
{
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
				gameover = false;
				running = 0;
				break;
			case SDLK_r:
				menu();
			}

			if (gameOverEvent.type == SDL_QUIT) {
				running = false;
				break;
			}

			if (!running) {
				gameover = 0;
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
				pause = 0;
				break;
			
			case SDLK_q:
				pause = 0;
				running = 0;
				break;
			}
			
			if (pauseEvent.type == SDL_QUIT) {
				running = false;
				break;
			}
			
			if (!running) {
				pause = 0;
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
				start();
				break;
		
			case SDLK_q:
				menu = false;
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

	Paddle paddle(345, 577, 15, 100, (192153131));
	Ball ball(395, 550, 20, (192153131));
	Bricks bricks;
	bricks.createBricks();

	// MAIN GAMELOOP	
	while (running) {
		//fps
		starting_tick = SDL_GetTicks();
		//fill screen with a white background
		SDL_FillRect(screen, NULL, 0xFFFFFF);
		paddle.draw(screen);
		ball.checkPaddleHit(paddle.getRect(), ball);
		ball.checkWalls();
		ball.moveBall();
		ball.draw(screen);
		bricks.drawBricks(screen);
		bricks.checkBricks(ball);
		
		if (ball.checkGameOver()) {
			gameOver();
		}
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
				break;
			case SDLK_r:
				start();
			}

			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}
		}
		SDL_UpdateWindowSurface(window);
		SDL_FreeSurface(screen);

		//FRAMERATELOCK
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

