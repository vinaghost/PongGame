#include "Item.h"


#include <iostream>
using namespace std;

Item::Item(RenderWindow* window): Entity(window, 0, 0)
{
	shape = new CircleShape(10);
	used = false;
	spawned = false;
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

void Item::setUsed(bool used)
{
	this->used = used;
}

string Item::getNameItem()
{
	return this->name;
}


void Item::spawn()
{
	// đã xuất hiện trên màn hình.
	if (this->spawned) return;

	// Ngược lại, vẽ và xác nhận Item đã xuất hiện.
	this->draw();
	this->spawned = true;
}
void Item::despawn()
{
	// đã biến mất khỏi màn hình.
	if (!this->spawned) return;

	// Ngược lại, xóa và xác nhận Item đã biến mất.
	//cau lenh xoa 

	//cau lenh xoa
	this->spawned = false;
}