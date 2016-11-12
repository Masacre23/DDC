#ifndef __Player__
#define __Player__

#include <vector>
#include "entity.h"
#include "room.h"
#include "exit.h"

class Room;

using namespace std;

class Player : public Entity
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	bool Go(const vector<string>& args);
	void Look(const vector<string>& args) const;

	Room* GetRoom() const;
};

#endif