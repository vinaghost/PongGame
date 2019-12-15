#include "brick.h"

Brick::Brick(RenderWindow* window) : Item(window)
{
	setNameItem("Brick");
}

Brick::~Brick()
{
}

void Brick::active(Entity* ball)
{
	setActived(true);
}

string Brick::getNameClass()
{
	return "Brick";
}