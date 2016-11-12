#ifndef __Exit__
#define __Exit__
#include <iostream>
#include "entity.h"

class Room;

using namespace std;

class Exit : public Entity
{
public:
	Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination);
	~Exit();

	void Look() const;
	Room* Exit::GetDestination(const Room* room) const;
	
	string opposite_name;
	Room* destination;
};

#endif