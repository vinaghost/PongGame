#pragma once

#include "item.h"
#include "board.h"

#include <vector>
using namespace std;

class ItemManager
{
private:
	vector<Item*> items;
	vector<bool> spawns;
	RenderWindow* window;
	int sl_hang, sl_cot;
public:
	ItemManager(RenderWindow* window, Board* b);
	~ItemManager();
	void addItem(Item*);
	void setRenderWindow(RenderWindow*);
	void processEvents();
	void draw();
	void createItem(Board* b);
	void destroyItem();
	vector<Item*> spawnedItem();
};
