#include "Item.h"

#include <iostream>
using namespace std;

Item::Item(RenderWindow* window) : Entity(window, 0, 0), actived(false)
{
	shape = new RectangleShape(Vector2f(50.0f, 30.0f));
	image.loadFromFile("Resources/brick.png");
	shape->setTexture(&image, true);
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

void Item::setActived(bool used)
{
	this->actived = used;
}

bool Item::getActived()
{
	return this->actived;
}

string Item::getNameItem()
{
	return this->name;
}

void Item::setRenderWindow(RenderWindow* window)
{
	this->window = window;
}