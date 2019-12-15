#pragma once
#include "item.h"

class BigBall: public Item
{
public:
	BigBall(RenderWindow* window);
	~BigBall();
	void active(Entity*);
	string getNameClass();
};

