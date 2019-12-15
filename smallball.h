#pragma once
#include "item.h"

class smallball : public Item
{
public:
	smallball(RenderWindow* window);
	~smallball();
	void active(Entity*);
	string getNameClass();
};

