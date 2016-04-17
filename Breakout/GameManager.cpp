#include "GameManager.h"


GameManager::GameManager()
{
}


void GameManager::gameOver()
{
	//gameover loop
	//Draw picture of gameoverscreen
	//press r for restart
	//q to quit
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
			}
		}

	}
}

void GameManager::menu()
{
	bool menu = true;
	SDL_Event menuEvent;
	while(menu){
		//draw menu "PRESS S TO START"
		while (SDL_PollEvent(&menuEvent)) {
			switch (menuEvent.key.keysym.sym) {
			case SDLK_s:
				menu = false;
				break;
			}
		}
		
	}
}

