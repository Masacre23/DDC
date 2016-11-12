#include "exit.h"
#include "room.h"


Exit::Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination) :
Entity(name, description, (Entity*) origin),opposite_name(opposite_name), destination(destination)
{
	type = EXIT;
	destination->container.push_back(this);
}


Exit::~Exit()
{

}

void Exit::Look() const
{
	cout << "You are going to " + opposite_name;
}

Room* Exit::GetDestination(const Room* room) const
{
	if (room == parent)
		return destination;
	if (room == destination)
		return (Room*)parent;

	return NULL;
}