// DDC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
//main -> world -> entity -> creature, items, exit, rooms
using namespace std;


void Tokenize(string s, vector <string> v)
{
	char str[1024];
	strncpy_s(str, s.c_str(), sizeof(str));
	str[sizeof(str) - 1] = 0;
	//char* pch;
	//pch = strtok(str, ",-");
	//string aux;

	//for (int i = 0; i )
}

int main()
{
	char keypressed;
	string player_input;
	bool repeat = true;
	vector<string> arguments;
	cout << "Welcome to Disco Dance club" << endl;
	cout << ">";
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
					//cout << " ";
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


