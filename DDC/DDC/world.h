#include <string>
#include <list>
#include <vector>
#include <iostream>
#include "npc.h"

using namespace std;

class Entity;
class Player;

class World
{
public:
	World();
	~World();

	bool ParseCommand(vector<string>& args);

private:
	list<Entity*> entities;
	Player* player;
};

