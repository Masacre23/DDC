#ifndef __NPC__
#define __NPC__

#include "entity.h"
#include "room.h"

class Room;

using namespace std;

class NPC : public Entity
{
public:
	NPC(const char* name, const char* description, Room* room);
	~NPC();

	void Look() const;
};

#endif