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
	//Room* gym = new Room("Gym", "You")

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
	//Hanna
	int charmRequired[3] = {20,30,40};
	int popularityRequired[3] = { 0,0,0 };
	int strenghtRequired[3] = { 0,10,20 };
	int intelligenceRequired[3] = { 0,0,0 };

	string goodReactions[9];
	goodReactions[0] = "You: WOOOO i like this song!!.\n\nThe music is strong and she can´t listen you but she smiles.(+1 relation, +1 pop)"; //Chat
	goodReactions[1] = "You: What do you think about Roberto?\nHanna: I hate Roberto, he thiks he is smart but is a f***in idiot.(+2 relation, +1 pop)"; //Gossip
	goodReactions[2] = "You: Your outfit is cool.\nHanna: I know.(+3 relation, +1 pop)"; //Compliment
	goodReactions[3] = "Hanna: Hmmm...tasty.(+4 relation, +5 pop)"; //Give Gift
	goodReactions[4] = "You dance with Hanna. (+5 relation, +2 pop, +2 strength)"; //Dance 
	goodReactions[5] = "Awwwwww...so cute. (+6 relation, +2 pop)"; //Hug 
	goodReactions[6] = "You have kissed Hanna. (+7 relation, +3 pop)"; //kiss 
	goodReactions[7] = "Ommgg O.o (+8 relation, +3 pop)"; //Wohooo 
	goodReactions[8] = "You: Hanna...do you want to marry me?\nOmgg i can`t believe it, of course!!! (+9 relation, +5 pop)"; //Propose Marriage
 
	string badReactions[12];
	badReactions[0] = "You: Hi beauty...\nHanna: Please go away. (-2 relation)"; //Chat 
	badReactions[1] = "You: I think Roberto is cool...\nHanna: Aght... (-3 relation)"; //Gossip 
	badReactions[2] = "You: You are so hot.\nHanna: Talk to the hand. (-4 relation)"; //Compliment 
	badReactions[3] = "You don`t have a gift."; //Give Gift 
	badReactions[4] = "Hanna: Keep trying. (-5 relation)"; //Dance 
	badReactions[5] = "Hanna: Ught you smell out. (-6 relation)"; //Hug 
	badReactions[6] = "Hanna: What are you trying?. (-7 relation)"; //kiss 
	badReactions[7] = "Hanna: Take your hands off me. POLICEEE! (-8 relation)"; //Wohooo 
	badReactions[8] = "You: Hanna...do you want to marry me?\nHanna: Are you crazy?? (-9 relation)"; //Propose Marriage 
	badReactions[9] = "You: Beach.\nHanna: Excuse me!?!? (-10 relation)"; //Insult 
	badReactions[10] = "You slapped her face...and she slaps you harder. (-11 relation)"; //Slap 
	badReactions[11] = "You win the fight and she looks angry. (-12 relation)"; //Fight 

	NPC* npc1 = new NPC("Hanna", "Nice girl", disco, charmRequired, popularityRequired, strenghtRequired, intelligenceRequired, goodReactions, badReactions);

	//Roberto
/*	charmRequired[3] = { 0,0,0 };
	popularityRequired[3] = { 20,30,40 };
	strenghtRequired[3] = { 0,0,0 };
	intelligenceRequired[3] = { 0,10,20 };
	NPC* npc2 = new NPC("Roberto", "Nice guy", disco, charmRequired, popularityRequired, strenghtRequired, intelligenceRequired);
	*/
	entities.push_back(npc1);
	//entities.push_back(npc2);

	//Player
	player = new Player("Adrián", "You are cool", home, 0,0,0,0,0);

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
	else if (args[0] == "talk")
	{
		player->Talk(args);
		return true;
	}
	else if (args[0] == "work")
	{
		player->Work();
		return true;
	}
	else if (args[0] == "drink")
	{
		player->Drink();
		return true;
	}
	else
		return false;
}
