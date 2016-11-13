#include "world.h"
#include "entity.h"
#include "room.h"
#include "player.h"
#include "exit.h"
#include "item.h"


World::World()
{
	//Rooms
	Room* home = new Room("Home", "Dirty house.");
	Room* street = new Room("Street", "You listen the music at the other side of the street.");
	Room* work = new Room("Work", "Zzzzz...so boring.");

	Exit* exit1 = new Exit("home", "street", "descripcion?", home, street);
	Exit* exit2 = new Exit("home", "work", "descripcion?", home, work);

	entities.push_back(home);
	entities.push_back(street);
	entities.push_back(work);

	entities.push_back(exit1);
	entities.push_back(exit2);

	//Items

	Item* chocolateBox = new Item("chocolate", "A box", home);
	Item* bombon = new Item("bombom", "A box", chocolateBox);

	entities.push_back(chocolateBox);
	entities.push_back(bombon);

	//Player
	player = new Player("Adrián", "You are cool", home);

	entities.push_back(player);
}


World::~World()
{
	for (auto a = entities.begin(); a != entities.end(); ++a)
		delete *a;
	entities.clear();
}

bool World::ParseCommand(vector<string>& args)
{
	if (args[0] == "look")
	{
		player->Look(args);
		return true;
	}
	else if (args[0] == "go")
	{
		player->Go(args);
	}
	else if (args[0] == "stats")
	{
		player->Stats();
	}
	else
		return false;
}
