#pragma once

#include "Item.h"

class freezeBall_item : public Item
{
public:
	freezeBall_item(RenderWindow* window);
	~freezeBall_item();
	void active(Entity*);
	string getNameClass();
};

