#pragma once
#include "entity.h"

#include "ball.h"

class Item : public Entity
{
protected:
	string name;
	int soluong;
	bool used = false;
public:
	Item(RenderWindow* window, Board* b, float radius);
	~Item();
	void setNameItem(string name);
	void setSL(int sl);
	string getNameItem();
	int getSL();
	string getNameClass();
	void checkcollisionItem(Ball*);
	virtual void active(Ball*);
	void ItemoutBoard(Ball*);
};

