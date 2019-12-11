#pragma once
#include "entity.h"


class Item : public Entity
{
protected:
	string name;
	bool actived;
public:
	Item(RenderWindow* window);
	~Item();
	void setNameItem(string name);
	void setActived(bool);
	bool getActived();
	string getNameItem();
	string getNameClass();
	virtual void active(Entity*) = 0;
	void setRenderWindow(RenderWindow* window);
};

