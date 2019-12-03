#include "Item.h"


#include <iostream>
using namespace std;

Item::Item(RenderWindow* window, Board* b, float radius): Entity(window, b->getLeft() / 2 + b->getRight() / 2 - radius, b->getTop() / 2 + b->getBottom() / 2 - radius)
{
	shape = new CircleShape(radius);

}


Item::~Item()
{
}

string Item::getNameClass()
{
	return "Item";
}

void Item::setNameItem(string name)
{
	this->name = name;
}
void Item::setSL(int sl)
{
	this->soluong = sl;
}
string Item::getNameItem()
{
	return this->name;
}
int Item::getSL() 
{
	return this->soluong;
}

void Item::checkcollisionItem(Ball* b)
{
	if (this->isIntersect(*b))
	{
	    used = true;
	}
}

void Item::active(Ball* b)
{
	checkcollisionItem(b);
	if (used == true)
	{
		cout << "Cham vao roi" << endl;
		//Dua vao ten de thuc hien tinh nang cua Item
		if (name == "freeze")
		{
			b->speedDown(0.1f);
		}
	}
}

void Item::ItemoutBoard(Ball* b)
{
	if (used == true)
	{
		soluong--;
		//khong bk xoa item khoi man hinh .-.
	}
}