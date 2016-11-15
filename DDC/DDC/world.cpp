#include "world.h"
#include "entity.h"
#include "room.h"
#include "player.h"
#include "exit.h"
#include "item.h"
#include "npc.h"


World::World()
{
	//Rooms
	Room* home = new Room("Home", "Dirty house.");
	Room* street = new Room("Street", "You listen the music at the other side of the street.");
	Room* work = new Room("Work", "Zzzzz...so boring.");
	Room* disco = new Room("Disco", "Puncha puncha puncha.");

	Exit* exit1 = new Exit("home", "street", "descripcion?", home, street);
	Exit* exit2 = new Exit("home", "work", "descripcion?", home, work);
	Exit* exit3 = new Exit("street", "disco", "descripcion?", street, disco);

	entities.push_back(home);
	entities.push_back(street);
	entities.push_back(work);
	entities.push_back(disco);

	entities.push_back(exit1);
	entities.push_back(exit2);
	entities.push_back(exit3);

	//Items

	Item* chocolateBox = new Item("chocolate", "A box", home, false);
	Item* bombon = new Item("bombon", "A box", chocolateBox, true);

	entities.push_back(chocolateBox);
	entities.push_back(bombon);

	//NPCs
	NPC* npc1 = new NPC("Hanna", "Nice girl", disco);

	entities.push_back(npc1);
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
		return true;
	}
	else if (args[0] == "stats")
	{
		player->Stats();
		return true;
	}
	else if (args[0] == "inventory")
	{
		player->Inventory();
		return true;
	}
	else if (args[0] == "take" && args.size() > 1)
	{
		player->Take(args);
		return true;
	}
	else if (args[0] == "drop" && args.size() > 1)
	{
		player->Drop(args);
		return true;
	}
	else if (args[0] == "put" && args.size() == 4)
	{
		player->Put(args);
		return true;
	}
	else
		return false;
}
