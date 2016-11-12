#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	NPC,
	PLAYER
};

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	virtual ~Entity();

	virtual void Look() const;
	void ChangeParentTo(Entity* new_parent);

	EntityType type;
	string name;
	string description;

	Entity* parent;
	list<Entity*> container;
};

#endif