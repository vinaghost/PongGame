#include "Brick.h"



Brick::Brick(RenderWindow* window) : Item(window)
{
	setNameItem("Brick");
}


Brick::~Brick()
{
}

void Brick::active(Entity*)
{
	setActived(true);
}

string Brick::getNameClass()
{
	return "Brick";
}