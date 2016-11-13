#include <iostream>
#include "player.h"


Player::Player(const char* name, const char* description, Room* room) : 
Entity(name, description, room)
{
	type = PLAYER;
}


Player::~Player()
{
}

void Player::Look(const vector<string>& args) const
{
	if (args.size() > 1)
	{
		for (auto a = parent->container.begin(); a != parent->container.cend(); ++a)
		{
			if (args[1] == (*a)->name)
			{
				(*a)->Look();
				return;
			}
		}

		if (args[1] == "myself")
		{
			cout << "You are " + name + " " + description << endl;
		}
	}
	else
	{
		parent->Look();
	}
}

Room* Player::GetRoom() const
{
	return (Room*)parent;
}

bool Player::Go(const vector<string>& args)
{
	Exit* exit = GetRoom()->GetExit(args[1]);
	if (exit == NULL)
		return false;

	cout <<"\nYou have come to " + args[1] + "...\n";

	ChangeParentTo(exit->GetDestinationFrom((Room*)parent));

	return true;
}

void Player::Stats() const
{
	cout << "\nPopularity: " << popularity << endl;
	cout << "Intelligence: " << intelligence << endl;
	cout << "Strength: " << strength << endl;
	cout << "Charm: " << charm << endl;
	cout << "Relationship with Hanna: " << relationship1 << endl;
	cout << "Relationship with Roberto: " << relationship2 << endl;
}



