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

void Player::Inventory() const
{
	string s;
	bool b = false;

	for (auto a = container.begin(); a != container.cend(); ++a)
	{
		if ((*a)->type == ITEM && (*a)->parent->type == PLAYER)
		{
			b = true;
			s = s + (*a)->name;
		}
	}
	if (b)
	{
		cout << "\nList of items:\n" << s << endl;
	}
	else
		cout << "\nYou don't have any items.\n";
}

bool Player::Take(const vector<string>& args)
{
	
		/*for (auto a = parent->container.begin(); a != parent->container.cend(); ++a)
		{
			if ((*a)->type == ITEM && (*a)->name == args[1])
			{

				(*a)->ChangeParentTo(this);

				cout << "\nYou have taked " << (*a)->name << ".\n";
				return;
			}

		}*/
	if (args.size() == 4)
	{
		Item* item = (Item*)parent->Find(args[3], ITEM);

		if (item == NULL)
			item = (Item*)Find(args[3], ITEM);

		if (item == NULL)
		{
			cout << "\nThere is no item with that name.\n";
			return false;
		}

		Item* subitem = (Item*)item->Find(args[1], ITEM);

		if (subitem == NULL)
		{
			cout << "\n" << item->name << " does not contain '" << args[1] << "'.\n";
			return false;
		}

		cout << "\nYou take " << subitem->name << " from " << item->name << ".\n";
		subitem->ChangeParentTo(this);
	}
	
	if (args.size() == 2)
	{
		Item* item = (Item*)parent->Find(args[1], ITEM);

		if (item == NULL)
		{
			cout << "\nThere is no item with that name.\n";
			return false;
		}
		cout << "\nYou have taked " << item->name << ".\n";
		item->ChangeParentTo(this);

	}
	return true;
	//cout << "\nThere is no item with that name.\n";
}

void Player::Drop(const vector<string>& args)
{
	for (auto a = container.begin(); a != container.cend(); ++a)
	{
		if ((*a)->type == ITEM && (*a)->name == args[1])
		{
			cout << "\nYou have dropped " << (*a)->name << ".\n";
			(*a)->ChangeParentTo(parent);
			return;
		}
	}
	cout << "\nThere is no item with that name in your inventory.\n";
}

bool Player::Put(const vector<string>& args)
{
	bool b = false;
	if (args.size() == 4)
	{
		Item* container = (Item*)parent->Find(args[3], ITEM);
	
		if (container == NULL)
		{
			cout << "\nThere is no item with that name.\n";
			return false;
		}
		Item* item = (Item*)Find(args[1], ITEM);
		
		if (item == NULL)
		{
			cout << "\nThere is no item with that name.\n";
			return false;
		}

		cout << "\nYou put " << item->name << " into " << container->name << ".\n";
		item->ChangeParentTo(container);

		return true;
	}
	return false;
}

void Player::Talk(const vector<string>& args)
{
	bool b = false;

	for (auto a = parent->container.begin(); a != parent->container.cend(); ++a)
	{
		if ((*a)->type == PEOPLE && (*a)->name == args[1])
		{
			while (true)
			{
				cout << "\n1.- ";
				break;
			}
		}
	}

}