#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include "world.h"
#include "auxiliar.h"

using namespace std;

int main()
{
	char keypressed;
	string player_input;
	bool repeat = true;
	vector<string> arguments;

	system("color 0E");
	cout << "Welcome to Disco Dance club" << endl;
	cout << "Your mission is to find the love of your life, you only have 10 days.\nBefore starting you need to answer a few questions:\n";
	
	World myWorld;

	cout << "\nNow you can start the game, write 'help' if you don't know the commands.\n";

	arguments.push_back("look");
	myWorld.ParseCommand(arguments);
	arguments.clear();
	cout << "\n> ";

	while (repeat)
	{
		if (_kbhit())
		{
			keypressed = _getch();
			switch (keypressed)
			{
				case 27:
					repeat = false;
					break;
				case '\r': //return
					Tokenize(player_input, arguments);

					if (!myWorld.ParseCommand(arguments))
						cout << "\n Sorry I don't understand." << endl;

					if (arguments.size() > 0)
					{
						arguments.clear();
						player_input = "";
						cout << "\n> ";
					}
					break;
				case '\b': //backspace
					if (player_input.length() > 0)
					{
						player_input.pop_back();
						cout << "\b \b";
					}

					break;
				default:
					player_input += keypressed;
					cout << keypressed;
					break;

			}
		}
	}
	cout << "Thanks for playing" << endl;
	return 0;
}


