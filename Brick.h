#pragma once

#include "item.h"
#include "board.h"

#include <vector>
using namespace std;

class Brick: public Item
{
public:
	Brick(RenderWindow* window);
	~Brick();
	string getNameClass();
	void active(Entity*);
};

