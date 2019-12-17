#include "itemManager.h"

#include "freezeBall_item.h"
#include "brick.h"
#include "bigball.h"
#include "smallball.h"
#include "bigpaddle.h"
#include "smallpaddle.h"

#include <stdlib.h>
#include <time.h>

ItemManager::ItemManager(RenderWindow* window, Board* b) : window(window)
{
	sl_cot = (int)(b->getRight() - b->getLeft() - 50.0f) / 50;
	sl_hang = (int)((b->getBottom() - b->getTop()) / 2 - 20.0f) / 30;
}

ItemManager::~ItemManager()
{
	destroyItem();
}

void ItemManager::setRenderWindow(RenderWindow* window)
{
	this->window = window;
}

void ItemManager::addItem(Item* object)
{
	items.push_back(object);
	spawns.push_back(true);
}

void ItemManager::processEvents()
{
	for (size_t i = 0; i < items.size(); i++)
	{
		if (items[i]->getActived() == true)
		{
			spawns[i] = false;
		}
	}
}

void ItemManager::draw()
{
	for (size_t i = 0; i < items.size(); i++)
	{
		if (spawns[i])
		{
			items[i]->draw();
		}
	}
}
void ItemManager::destroyItem() {
	for (size_t i = 0; i < items.size(); i++) {
		delete items[i];
	}
	items.clear();
	spawns.clear();
}
void ItemManager::createItem(Board* b)
{
	destroyItem();
	int a[5];
	Item* object;
	int linenow = 0, columnnow = 0;
	srand((int)time(0));
	for (int i = 0; i < 5; i++)
	{
		a[i] = rand() % (sl_cot * sl_hang + 2 + 1);
	}
	for (int i = 0; i <= sl_cot * sl_hang + 2; i++)
	{
		if (i == a[0])
		{
			object = new freezeBall_item(window);
		}
		else if (i == a[1])
		{
			object = new smallball(window);
		}
		else if (i == a[2])
		{
			object = new bigpaddle(window);
		}
		else if (i == a[3])
		{
			object = new smallpaddle(window);
		}
		else if (i == a[4])
		{
			object = new BigBall(window);
		}
		else
		{
			object = new Brick(window);
		}

		if (columnnow == sl_cot - 1)
		{
			columnnow = 0;
			linenow++;
		}
		object->setX(b->getLeft() + 50.0f + 50.0f*columnnow);
		object->setY(b->getTop() + 20.0f + 30.0f*linenow);
		addItem(object);
		columnnow++;
	}
}

vector<Item*> ItemManager::spawnedItem()
{
	vector<Item*> spawnedItems;
	for (size_t i = 0; i < items.size(); i++)
	{
		if (spawns[i] == true)
		{
			spawnedItems.push_back(items[i]);
		}
	}
	return spawnedItems;
}