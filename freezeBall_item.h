#pragma once

#include "Item.h"

class freezeBall_item : public Item
{
public:
	freezeBall_item(RenderWindow* window, Board* b, float radius);
	~freezeBall_item();
};

