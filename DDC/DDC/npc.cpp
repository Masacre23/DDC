#include <iostream>
#include "npc.h"


NPC::NPC(const char* name, const char* description, Room* room) :
	Entity(name, description, room)
{
	type = PEOPLE;
}


NPC::~NPC()
{
}

void NPC::Look() const
{
	cout <<endl << name << endl << description;
}


