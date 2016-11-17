#include <iostream>
#include "room.h"
#include "exit.h"
#include "item.h"
#include "npc.h"


Room::Room(const char* name, const char* description) : Entity(name, description, NULL)
{
	type = ROOM;
}

//****************************************************************************//
Room::~Room()
{
}

//****************************************************************************//
void Room::Look() const
{
	cout << "\n" + name + "\n" + description + "\n";
	bool b = false;
	string s;

	//Exit
	int numExits = 1;
	for (auto a = container.begin(); a != container.end(); ++a)
	{
		if ((*a)->type == EXIT)
		{
			Exit* ex = (Exit*)*a;
			if(numExits == 1)
				cout << "\nYou can exit " + ex->GetNameFrom(this) + " and go to " + ex->GetDestinationFrom(this)->name;
			if (numExits == 2)
				cout << " or " + ex->GetDestinationFrom(this)->name;
			if (numExits > 2)
				cout << ", " + ex->GetDestinationFrom(this)->name;
			numExits++;
		}
	}
	cout << ".\n";

	//Items
	s = "Items in the room:\n";
	for (auto a = container.begin(); a != container.end(); ++a)
	{
		if ((*a)->type == ITEM)
		{
			b = true;
			s += (*a)->name + "\n";
		}
	}
	if (b)
		cout << s;

	//NPCs
	b = false;
	s = "People in the room:\n";
	for (auto a = container.begin(); a != container.cend(); ++a)
	{
		if ((*a)->type == PEOPLE)
		{
			b = true;
			s += (*a)->name + "\n";
		}
	}
	if (b)
		cout << s;
}

//****************************************************************************//
Exit* Room::GetExit(const string& direction) const
{
	for (auto a = container.begin(); a != container.end(); ++a)
	{
		if ((*a)->type == EXIT)
		{
			Exit* ex = (Exit*)*a;
			if (ex->opposite_name == direction || ex->name == direction)
			{
				return ex;
			}
		}
	}
	cout << "\nYou can`t go there.\n";
	return NULL;
}
