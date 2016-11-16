#include "world.h"
#include "entity.h"
#include "room.h"
#include "player.h"
#include "exit.h"
#include "item.h"
#include "npc.h"
#include <windows.h>

World::World()
{
	//Rooms
	Room* home = new Room("Home", "Your house, very small and dirty but you have enough with that.");
	Room* street = new Room("Street", "You listen the music at the other side of the street.");
	Room* work = new Room("Work", "Zzzzz...so boring.");
	Room* disco = new Room("Disco", "Puncha puncha puncha.");
	Room* gym = new Room("Gym", "You see a lot of people taking selfies.");
	Room* library = new Room("Library", "The house of knowledge. ");

	Exit* exit1 = new Exit("home", "street", " ", home, street);
	Exit* exit2 = new Exit("home", "work", " ", home, work);
	Exit* exit3 = new Exit("street", "disco", " ", street, disco);
	Exit* exit4 = new Exit("street", "gym", " ", street, gym);
	Exit* exit5 = new Exit("street", "library", " ", street, library);

	entities.push_back(home);
	entities.push_back(street);
	entities.push_back(work);
	entities.push_back(disco);

	entities.push_back(exit1);
	entities.push_back(exit2);
	entities.push_back(exit3);
	entities.push_back(exit4);
	entities.push_back(exit5);

	//Items

	Item* box = new Item("box", "Heart-shaped box", home, false);
	Item* chocolate = new Item("chocolate", "You can use it as a gift.", box, true);

	entities.push_back(box);
	entities.push_back(chocolate);

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
	badReactions[3] = "She don't want gifts."; //Give Gift 
	badReactions[4] = "Hanna: Keep trying. (-5 relation)"; //Dance 
	badReactions[5] = "Hanna: Ught you smell out. (-6 relation)"; //Hug 
	badReactions[6] = "Hanna: What are you trying?. (-7 relation)"; //kiss 
	badReactions[7] = "Hanna: Take your hands off me. POLICEEE! (-8 relation)"; //Wohooo 
	badReactions[8] = "You: Hanna...do you want to marry me?\nHanna: Are you crazy?? (-9 relation)"; //Propose Marriage 
	badReactions[9] = "You: Beach.\nHanna: Excuse me!?!? (-10 relation)"; //Insult 
	badReactions[10] = "You slapped her face...and she slaps you harder. (-11 relation)"; //Slap 
	badReactions[11] = "She win the fight and she looks angry. (-12 relation)"; //Fight 

	NPC* npc1 = new NPC("Hanna", "Diva, sexy, she is out of your possibilities, ", disco, charmRequired, popularityRequired, strenghtRequired, intelligenceRequired, goodReactions, badReactions);

	//Roberto
	int charmRequired1[3] = { 0,0,0 };
	int popularityRequired1[3] = { 20,30,40 };
	int strenghtRequired1[3] = { 0,0,0 };
	int intelligenceRequired1[3] = { 0,10,20 };

	string goodReactions1[9];
	goodReactions1[0] = "You: WOOOO i like this song!!.\nRobert: I prefer beethoven but I admit it is not bad.(+1 relation, +1 pop)"; //Chat
	goodReactions1[1] = "You: What do you think about Hanna?\nRobert: She is in love with me but is not my type.(+2 relation, +2 pop)"; //Gossip
	goodReactions1[2] = "You: Your outfit is cool.\nRobert: Thanks my mother did it to me.(+3 relation, +3 pop)"; //Compliment
	goodReactions1[3] = "Robert: Yeeaaah, my inspiration...(+4 relation, +4 pop)"; //Give Gift
	goodReactions1[4] = "You dance with Robert. (+5 relation, +5 pop, +5 strength)"; //Dance 
	goodReactions1[5] = "Robert: ;). (+6 relation, +6 pop)"; //Hug 
	goodReactions1[6] = "You have kissed Robert. (+7 relation, +7 pop)"; //kiss 
	goodReactions1[7] = "<3 (+8 relation, +8 pop)"; //Wohooo 
	goodReactions1[8] = "You: Robert...do you want to marry me?\nOf course sweetheart. (+9 relation, +9 pop)"; //Propose Marriage

	string badReactions1[12];
	badReactions1[0] = "You: Hi sweetheart...\nRobert: This is your best shot?. (-2 relation)"; //Chat 
	badReactions1[1] = "You: I think Hanna is sexy...\nRobert: It's not my type... (-3 relation)"; //Gossip 
	badReactions1[2] = "You: You are so hot.\nRobert: You are not. (-4 relation)"; //Compliment 
	badReactions1[3] = "He don't want gifts."; //Give Gift 
	badReactions1[4] = "Robert: I prefer to dance alone. (-5 relation)"; //Dance 
	badReactions1[5] = "He dodge you. (-6 relation)"; //Hug 
	badReactions1[6] = "Robert: Eeeehm...nope. (-7 relation)"; //kiss 
	badReactions1[7] = "Robert: Take your hands off me. POLICEEE! (-8 relation)"; //Wohooo 
	badReactions1[8] = "You: Robert...do you want to marry me?\nRobert: NO...GOD...NO...GOD, PLEASE NO...NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO (-9 relation)"; //Propose Marriage 
	badReactions1[9] = "You: Nigga.\nRobert: Excuse me!?!? (-10 relation)"; //Insult 
	badReactions1[10] = "You slapped her face...and he slaps you harder. (-11 relation)"; //Slap 
	badReactions1[11] = "You win the fight and she looks angry. (-12 relation)"; //Fight 

	NPC* npc2 = new NPC("Robert", "A sexy black man, he is wearing very posh clothes.", disco, charmRequired1, popularityRequired1, strenghtRequired1, intelligenceRequired1, goodReactions1, badReactions1);
	
	entities.push_back(npc1);
	entities.push_back(npc2);

	//Player
	string genre;
	string name;
	int selection = 0, money = 0, charm = 0, popularity = 0, strenght = 0, intelligence = 0;
	cout << "\nYou are a man or a woman?\n>";
	cin >> genre;
	bool b = false;
	if (genre == "man" || genre == "woman")
		b = true;
	else
	{
		while (!b)
		{
			cout << "\nCome on, you are a man or a woman? Don't waste my time.\n>";
			cin >> genre;
			if (genre == "man" || genre == "woman")
				b = true;
		}
			
	}
	cout << "\nWhat's your name?\n>";
	cin >> name;
	cout << "How is your life?\n1.- I'm rich but unhappy.\n2.- I have a lot of friends in my town.\n3.- I live in a small farm, the cows are cute.\n>";
	
	while (selection < 1 || selection > 3)
	{
		cin >> selection;
		switch (selection)
		{
		case 1:
			cout << "\nYou are rich, you have a good education and you meet some important people. (+1000$, +20 intelligence, +5 popularity, +5 charm)\n";
			money = 1000;
			intelligence = 20;
			popularity = 5;
			charm = 5;
			break;
		case 2:
			cout << "\nYou are very popular and you know how to be popular. (+25 popularity, +15 charm)\n";
			popularity = 25;
			charm = 15;
			break;
		case 3:
			cout << "\nYou are a strong " + genre + "and you have a lot of animal friends. (+25 strenght, +5 charm, + 10 popularity)\n";
			strenght = 25;
			charm = 5;
			popularity = 10;
			break;
		default:
			cout << "\nYou can't brake the game.\n>";
			break;
		}
	}

	cout << "\nWhat do you do in your free time?\n1.- I like going sport.\n2.- Hang out with my friends.\n3.- Do extra work.\n>";
	selection = 0;
	while (selection < 1 || selection > 3)
	{
		cin >> selection;
		switch (selection)
		{
		case 1:
			cout << "\nYou are strong, and your muscles are sexy. (+15 strenght, +5 charm)\n";
			strenght += 5;
			charm += 5;
			break;
		case 2:
			cout << "\nYou are more popular. (+15 popularity, +5 charm)\n";
			popularity += 15;
			charm += 5;
			break;
		case 3:
			cout << "\nYour extra work give you 500$.\n";
			money += 500;
			break;
		default:
			cout << "\n  >:v\n>";
			break;
		}
	}
	player = new Player("Name", "You are cool", home, popularity, intelligence, strenght, charm, money);
	//player = new Player("Name", "You are cool", home, 100, 100, 100, 100, 1000);
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
	if (player->day >= 11)
	{
		cout << "\nYou lose the game ;__;\n";
		Sleep(5000);
		exit(0);
	}
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
	else if (args[0] == "exercise")
	{
		player->Exercise();
		return true;
	}
	else if (args[0] == "sleep")
	{
		player->Time(8, 0);
		cout << "\nYou have slept 8 hours.\n";
		return true;
	}
	else if (args[0] == "help")
	{
		cout << "\nCommands:";
		cout << "\nlook";
		cout << "\nlook 'something'";
		cout << "\ngo 'name of room'";
		cout << "\nstats";
		cout << "\ninventory";
		cout << "\ntake 'name of item'";
		cout << "\ntake 'item1' from 'item2'";
		cout << "\ndrop 'name of item'";
		cout << "\nput 'item1' on 'item2'";
		cout << "\ntalk 'name of person'";
		cout << "\nwork";
		cout << "\ndrink";
		cout << "\nexercise";
		cout << "\nsleep";
	}
	else
		return false;
}
