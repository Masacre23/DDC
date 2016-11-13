#ifndef __Item__
#define __Item__
#include "entity.h"

using namespace std;

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* room);
	~Item();

	void Look() const;
};

#endif