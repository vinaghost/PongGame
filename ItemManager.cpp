#include "itemManager.h"



#include "freezeBall_item.h"
#include "brick.h"
#include "bigball.h"

ItemManager::ItemManager(RenderWindow* window, Board* b) : window(window)
{
	sl_cot = (b->getRight() - b->getLeft() - 50.0f) / 50.0f;
	sl_hang = ((b->getBottom()  - b->getTop())/2 - 20.0f) / 30.0f;
}

ItemManager::~ItemManager()
{
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
		}
	}
}

void ItemManager::createItem(Board* b)
{
	Item* object;
	int linenow = 0, columnnow = 0;
	for (int i = 0; i <= sl_cot * sl_hang + 2; i++)
	{
		if (i == (sl_cot - 1)*(sl_hang - 1))
		{
			object = new freezeBall_item(window);
		}
		else if (i == (sl_cot - 2)*(sl_hang - 2) + 2)
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
	for (int i = 0; i < items.size(); i++)
	{
		if (spawns[i] == true)
		{
			spawnedItems.push_back(items[i]);
		}
	}
	return spawnedItems;
}