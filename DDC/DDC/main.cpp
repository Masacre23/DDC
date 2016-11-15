#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include "world.h"

using namespace std;


void Tokenize(string s, vector <string>& v)
{
	char str[1024];
	strncpy_s(str, s.c_str(), sizeof(str));
	str[sizeof(str) - 1] = 0;
	string aux = "";
	int numWords = 0;

	for (unsigned i = 0; i < s.size(); ++i)
	{
		if (str[i] != ' ')
		{
			aux = aux + str[i];
		}
		else {
			v.push_back(aux);
			aux = ""+NULL;
		}
	}
	v.push_back(aux);
}

int main()
{
	char keypressed;
	string player_input;
	bool repeat = true;
	vector<string> arguments;

	World myWorld;

	system("color 0E");

	cout << "Welcome to Disco Dance club" << endl;

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


