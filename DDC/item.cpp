#include "item.h"
#include <iostream>


Item::Item(const char* name, const char* description, Entity* parent, bool b):
Entity(name, description, parent), storable(b)
{
	type = ITEM;
}

//****************************************************************************//
Item::~Item()
{
}

//****************************************************************************//
void Item::Look() const
{
	cout << "\n" + name + "\n" + description + "\n";
	int numItems = 0;

	for (auto a = container.begin(); a != container.end(); ++a)
	{
		if ((*a)->type == ITEM)
		{
			if ((*a)->parent->type == ITEM) //If it's an item inside other
			{
				if (!numItems)
					cout << "It contains:\n" + (*a)->name + "\n";
				else
					cout << (*a)->name;
			}
		}
	}
}
