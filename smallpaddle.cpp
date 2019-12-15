#include "smallpaddle.h"

#include "paddle.h"

smallpaddle::smallpaddle(RenderWindow* window) :Item(window)
{
	setNameItem("smallpaddle");
	shape = new RectangleShape(Vector2f(50.0f, 30.0f));
	image.loadFromFile("Resources/smallpaddle.png");
	shape->setTexture(&image, true);
}


smallpaddle::~smallpaddle()
{
}

void smallpaddle::active(Entity* object)
{
	static_cast<Paddle*>(object)->setShape(0.5);

	setActived(true);
}

string smallpaddle::getNameClass()
{
	return "smallpaddle";
}