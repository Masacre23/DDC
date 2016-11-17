#include "entity.h"
#include <iostream>


Entity::Entity(const char* name, const char* description, Entity* parent = NULL) : name(name), description(description), parent(parent)
{
	type = ENTITY;

	if (parent != NULL)
		parent->container.push_back(this);
}

//****************************************************************************//
Entity:: ~Entity()
{
}

//****************************************************************************//
void Entity::Look() const
{
	cout << name << "\n";
	cout << description << "\n";
}

//****************************************************************************//
void Entity::ChangeParentTo(Entity* new_parent)
{
	if (parent != NULL)
		parent->container.remove(this);

	parent = new_parent;

	if (parent != NULL)
		parent->container.push_back(this);
}

//****************************************************************************//
Entity* Entity::Find(const string& name, EntityType type) const
{
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
	{
		if ((*it)->type == type)
		{
			if ((*it)->name == name)
				return *it;
		}
	}

	return NULL;
}