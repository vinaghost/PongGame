#pragma once
#include "item.h"

class smallpaddle : public Item
{
public:
	smallpaddle(RenderWindow* window);
	~smallpaddle();
	void active(Entity*);
	string getNameClass();
};

