// Breakout 

#include "GameManager.h"

using namespace std;

int main(int argc, char *argv[]) {
	
	//Start GameManager
	GameManager gm;
	
	//Initiate SDL and screen - fps_cap
	gm.init();
	
	//Start and draw menu to screen
	gm.menu();
	
	return 0;



}

