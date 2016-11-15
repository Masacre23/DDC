#include <iostream>
#include "player.h"


Player::Player(const char* name, const char* description, Room* room, int popularity, int intelligence, int strength, int charm, int money) :
Entity(name, description, room), popularity(popularity), intelligence(intelligence), strength(strength), charm(charm), money(money)
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
	cout << "Money: " << money << endl;
	//cout << "Relationship with Hanna: " << relationshipH << endl;
	//cout << "Relationship with Roberto: " << relationshipR << endl;
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
		if(container->storable == false && item->storable == true)
			item->ChangeParentTo(container);

		return true;
	}
	return false;
}

void Player::Talk(const vector<string>& args)
{
	bool b = false;
	int input;

	for (auto a = parent->container.begin(); a != parent->container.cend(); ++a)
	{
		if ((*a)->type == PEOPLE && (*a)->name == args[1])
		{
			NPC* npc = (NPC*)*a;
			while (true)
			{
				cout << "\n1.- Chat\n2.- Gossip\n3.- Compliment\n4.- Give Gift\n5.- Dance\n6.- Hug\n7.- Wohoo\n8.- Propose marriage\n9.- Insult\n10.- Slap\n11.- Fight\n>";
				cin >> input;
				if (input == NULL)
				{
					break;
				}
				if (charm >= npc->charmRequired[input / 3] && popularity >= npc->popularityRequired[input / 3] && popularity >= npc->strenghtRequired[input / 3] && intelligence >= npc->intelligenceRequired[input / 3] && npc->relationShip >= 30 * input / 3)
				{
					cout << "\n" << npc->goodReactions[input-1] << endl;
					npc->relationShip += 1 * input;
				}
				else
				{
					cout << "\n" << npc->badReactions[input-1] << endl;
					npc->relationShip -= 1 * input;
				}
				
				break;
			}
		}
	}
}

void Player::Work()
{
	if (parent->name == "Work")
	{
		money += 50;
		cout << "\nYou have obtained 50$.\n";
	}
	else
		cout << "\nYou can`t work here\n";
}

void Player::Exercise()
{
	if (parent->name == "Gym")
	{
		strength += 5;
		cout << "\nYou have obtained +5 strength.\n";
	}
	else
		cout << "\nYou can`t do exercise here\n";
}

void Player::Drink()
{
	if (parent->name == "Disco")
	{
		charm += 5;
		cout << "\nYou have obtained +5 charm.\n";
	}
	else
		cout << "\nYou can`t drink here\n";
}