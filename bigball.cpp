#include "bigball.h"

#include <iostream>

#include "ball.h"

BigBall::BigBall(RenderWindow* window): Item(window)
{
	setNameItem("bigball");
	shape = new RectangleShape(Vector2f(50.0f, 30.0f));
	image.loadFromFile("Resources/BigBall.png");
	shape->setTexture(&image, true);
}


BigBall::~BigBall()
{
}

void BigBall::active(Entity* object)
{
	std::cout << "Cham vao roi" << std::endl;
	static_cast<Ball*>(object)->setShape(2);
	static_cast<Ball*>(object)->setX(this->getX());
	static_cast<Ball*>(object)->setY(this->getY());
	setActived(true);
}

string BigBall::getNameClass()
{
	return "bigball";
}