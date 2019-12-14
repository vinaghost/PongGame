#include "freezeBall_item.h"

#include <iostream>

#include "ball.h"
using namespace std;

freezeBall_item::freezeBall_item(RenderWindow* window) : Item(window)
{
	setNameItem("freeze");
	shape = new RectangleShape(Vector2f(50.0f, 30.0f));
	image.loadFromFile("Resources/freeze.png");
	shape->setTexture(&image, true);
}

freezeBall_item::~freezeBall_item()
{
}

void freezeBall_item::active(Entity* object)
{
	cout << "Cham vao roi" << endl;
	static_cast<Ball*>(object)->speedUp(-0.5f);
	setActived(true);
}

string freezeBall_item::getNameClass()
{
	return "freeze";
}