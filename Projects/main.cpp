#include <iostream>
#include <string>
#include <cctype>
#include "Connect4.h"
using namespace std;

void GameApp()
{
	int value;
	Connect4 game;
	char choice;

	while(true)
	{
		while(!game.HasWinner())
		{
			cout << game << "\n";
			cout << "Current Player: " << game.CurrentPlayer() << "\n\n";

			cout << "Enter a column: ";
			cin >> value;

			if(!game.MakeMove(value))
			{
				cout << "Column is invalid\n";
			}
		}
		cout << "\nThe winner is " << game.CurrentPlayer() << "\nRestart [Y]: ";
		cin >> choice;

		if(toupper(choice) == 'Y')
		{
			game.Reset();
		}
		else 
		{
			break;
		}
	}
}

int main()
{
	GameApp();
	return 0;
}
