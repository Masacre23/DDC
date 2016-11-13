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

const string& Exit::GetNameFrom(const Room* room) const
{
	if (room == parent)
		return name;
	if (room == destination)
		return opposite_name;

	return name;
}

Room* Exit::GetDestinationFrom(const Room* room) const
{
	if (room == parent)
		return destination;
	if (room == destination)
		return (Room*)parent;

	return NULL;
}