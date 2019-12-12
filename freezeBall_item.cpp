#include "freezeBall_item.h"

#include <iostream>
using namespace std;

freezeBall_item::freezeBall_item(RenderWindow* window) : Item(window)
{
	setNameItem("freeze");

}


freezeBall_item::~freezeBall_item()
{
}

void freezeBall_item::active(Entity* object)
{
	cout << "Cham vao roi" << endl;
}

string freezeBall_item::getNameClass()
{
	return "freeze";
}