#include "freezeBall_item.h"



freezeBall_item::freezeBall_item(RenderWindow* window, Board* b, float radius) : Item(window, b, radius)
{
	setNameItem("freeze");
	setSL(1);


	setX(b->getLeft() / 2 + 40 + b->getRight() / 2 - radius);
	setY(b->getTop() / 2 + 10 + b->getBottom() / 2 - radius);
}


freezeBall_item::~freezeBall_item()
{
}
