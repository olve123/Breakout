// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

# include "stdafx.h"
# include <iostream>
using  namespace std;


int main()
{
	int menu;

	do
	{


		cout<<endl

			<< "Breakout \n"
			<< "By Lars, Olve and Christopher \n\n"
			<< " 1 - Start the game.\n"
			<< " 2 - Controls.\n"
			<< " 3 - Exit.\n \n";
		cin>>menu;

		switch (menu)
		{

		case 1:
			//Start the game.
			break;

		case 2:
			//Controls, an overview of how to play the Breakout game.
			cout<<"Your goal is to bounce the ball on your paddle and destroy as many of the colored squares as you can without having the ball drop beneath you. \n";
			cout<<"<- and -> to move in either direction. \n";
				break;

		case 3:
			//Exit the game.
			cout<<"Thank you for playing \n";
				break;
			

		default:
			//Invalid menu choice. 
			cout<<"Please select something from the menu \n\n";
			break;
		}

	} while (menu != 3);
	return 0;
}