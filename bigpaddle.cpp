#include "bigpaddle.h"

#include "paddle.h"

bigpaddle::bigpaddle(RenderWindow* window):Item(window)
{
	setNameItem("bigpaddle");
	shape = new RectangleShape(Vector2f(50.0f, 30.0f));
	image.loadFromFile("Resources/bigpaddle.png");
	shape->setTexture(&image, true);
}


bigpaddle::~bigpaddle()
{
}

void bigpaddle::active(Entity* object)
{
	static_cast<Paddle*>(object)->setShape(2);
	
	setActived(true);
}

string bigpaddle::getNameClass()
{
	return "bigpaddle";
}