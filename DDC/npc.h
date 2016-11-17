#ifndef __NPC__
#define __NPC__

#include "entity.h"
#include "room.h"
#include <string>

class Room;

using namespace std;

class NPC : public Entity
{
public:
	NPC(const char* name, const char* description, Room* room, int charm[3], int popularity[3], int strength[3], int intelligence[3], string greaction[9], string breaction[11]);
	~NPC();

	void Look() const; //Show info about the NPC

	int relationShip;

	//Habilities required for speak with the npcs
	int charmRequired[3];
	int popularityRequired[3];
	int strenghtRequired[3];
	int intelligenceRequired[3];

	//The conversations
	string goodReactions[9];
	string badReactions[12];
};

#endif