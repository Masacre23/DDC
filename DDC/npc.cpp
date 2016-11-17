#include <iostream>
#include "npc.h"


NPC::NPC(const char* name, const char* description, Room* room, int charm[3], int popularity[3], int strenght[3], int intelligence[3], string gReactions[9], string bReactions[11]) :
	Entity(name, description, room)
{
	type = PEOPLE;
	for (int i = 0; i <= 11; ++i)
	{
		if (i < 3)
		{
			charmRequired[i] = charm[i];
			popularityRequired[i] = popularity[i];
			strenghtRequired[i] = strenght[i];
			intelligenceRequired[i] = intelligence[i];
		}
		if (i < 9)
			goodReactions[i] = gReactions[i];
		badReactions[i] = bReactions[i];
	}
}

//****************************************************************************//
NPC::~NPC()
{
}

//****************************************************************************//
void NPC::Look() const
{
	cout <<endl << name << endl << description;
}


