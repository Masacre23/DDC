#ifndef __Item__
#define __Item__
#include "entity.h"

using namespace std;

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* room, bool b);
	~Item();

	void Look() const; //Show information about the item

	bool storable;
};

#endif