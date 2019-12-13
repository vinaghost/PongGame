#pragma once

#include "Item.h"

#include <vector>
using namespace std;

class ItemManager
{
private:
	vector<Item*> items;
	vector<bool> spawns;
	RenderWindow* window;
public:
	ItemManager(RenderWindow* window);
	~ItemManager();
	void addItem(Item*);
	void setRenderWindow(RenderWindow*);
	void processEvents();
	void draw();
	void createItem();
	vector<Item*> spawnedItem();
};
