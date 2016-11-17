#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <windows.h>
#include "npc.h"
#include "player.h"
#include "entity.h"
#include "room.h"
#include "player.h"
#include "exit.h"
#include "item.h"
#include "npc.h"

using namespace std;

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

