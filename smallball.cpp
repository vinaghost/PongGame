#include "smallball.h"

#include "ball.h"

smallball::smallball(RenderWindow* window) : Item(window)
{
	setNameItem("smallball");
	shape = new RectangleShape(Vector2f(50.0f, 30.0f));
	image.loadFromFile("Resources/smallball.png");
	shape->setTexture(&image, true);
}


smallball::~smallball()
{
}


void smallball::active(Entity* object)
{
	static_cast<Ball*>(object)->setShape(0.5f);
	static_cast<Ball*>(object)->setX(this->getX());
	static_cast<Ball*>(object)->setY(this->getY());
	setActived(true);
}

string smallball::getNameClass()
{
	return "smallball";
}