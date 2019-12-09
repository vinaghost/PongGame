#pragma once
#include "entity.h"


class Item : public Entity
{
protected:
	string name;
	bool used, spawned;
public:
	Item(RenderWindow* window);
	~Item();
	void setNameItem(string name);
	void setUsed(bool);
	string getNameItem();
	string getNameClass();
	virtual void active(Entity*) = 0;
	void spawn();
	void despawn();
	void setRenderWindow(RenderWindow* window);
};

