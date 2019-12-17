#pragma once
#include "item.h"

class bigpaddle: public Item
{
public:
	bigpaddle(RenderWindow* window);
	~bigpaddle();
	void active(Entity*);
	string getNameClass();
};

