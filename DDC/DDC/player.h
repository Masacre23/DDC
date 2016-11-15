#ifndef __Player__
#define __Player__

#include <vector>
#include "entity.h"
#include "room.h"
#include "exit.h"
#include "item.h"

class Room;

using namespace std;

class Player : public Entity
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	bool Go(const vector<string>& args);
	void Look(const vector<string>& args) const;
	void Stats() const;
	void Inventory() const;
	bool Take(const vector<string>& args);
	void Drop(const vector <string>& args);
	void Talk(const vector<string>& args);
	bool Put(const vector<string>& args);

	Room* GetRoom() const;

	int popularity, intelligence, strength, charm, relationship1, relationship2;
};

#endif