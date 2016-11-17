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
	PEOPLE,
	PLAYER
};

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	virtual ~Entity();

	virtual void Look() const; //Describe the room
	void ChangeParentTo(Entity* new_parent); 
	Entity* Find(const string& name, EntityType type) const;

	EntityType type;
	string name;
	string description;

	Entity* parent;
	list<Entity*> container;
};

#endif