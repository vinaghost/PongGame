#include "ItemManager.h"

#include "board.h"

ItemManager::ItemManager(RenderWindow* window) : window(window)
{
}

ItemManager::~ItemManager()
{
}

void ItemManager::setRenderWindow(RenderWindow* window)
{
	this->window = window;
}

void ItemManager::setItem(Item* object)
{
	items.push_back(object);
	spawns.push_back(false);
}

void ItemManager::processEvents()
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i]->getActived() == true)
		{
			spawns[i] = false;
		}
	}
}

void ItemManager::draw()
{
	for (int i = 0; i < items.size(); i++)
	{
		if (spawns[i])
		{
			items[i]->draw();
			break;
		}
	}
}

void ItemManager::createItem()
{
	Board b(window);

	int i = 0;

	items[i]->setX(b.getLeft() / 2 + b.getRight() / 2 + 30.0f);
	items[i]->setY(b.getTop() / 2 + b.getBottom() / 2 + 50.0f);

	spawns[i] = true;
}

vector<Item*> ItemManager::spawnedItem()
{
	vector<Item*> spawnedItems;
	for (int i = 0; i < items.size(); i++)
	{
		if (spawns[i] == true)
		{
			spawnedItems.push_back(items[i]);
		}
	}
	return spawnedItems;
}