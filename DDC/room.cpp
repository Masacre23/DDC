#include <iostream>
#include "room.h"
#include "exit.h"


Room::Room(const char* name, const char* description) : Entity(name, description, NULL)
{
	type = ROOM;
}


Room::~Room()
{
}

void Room::Look() const
{
	cout << "\n" + name + "\n" + description + "\n";

	//Exit
	int numExits = 1;
	for (auto a = container.begin(); a != container.end(); ++a)
	{
		if ((*a)->type == EXIT)
		{
			Exit* ex = (Exit*)*a;
			if(numExits == 1)
				cout << "\nYou can exit for the " + ex->name + " and go to the " + ex->opposite_name;
			if (numExits == 2)
				cout << " or " + ex->opposite_name;
			numExits++;
		}
	}
	cout << ".";
}

Exit* Room::GetExit(const string& direction) const
{
	for (auto a = container.begin(); a != container.end(); ++a)
	{
		if ((*a)->type == EXIT)
		{
			Exit* ex = (Exit*)*a;
			if (ex->opposite_name == direction)
			{
				return ex;
			}
		}
	}
	return NULL;
}
