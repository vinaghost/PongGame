#include "ItemManager.h"



ItemManager::ItemManager(RenderWindow* window): window(window)
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

void ItemManager::draw(string name_item)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i]->getNameItem() == name_item)
		{
			items[i]->draw();
			break;
		}
	}
}

void ItemManager::createItem()
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i]->getActived() == false)
		{
			items[i]->setX(50.0f);
			items[i]->setY(50.0f);
			spawns[i] = true;
			break;
		}
	}
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