#include "paddle.h"

Paddle::Paddle(RenderWindow* window, Board* b) : MovingEntity(window, b, b->getLeft() / 2 + b->getRight() / 2 - default_width / 2, b->getBottom() - default_height * 2) {
	shape = new RectangleShape(Vector2f(default_width, default_height));
	float x = b->getLeft() / 2 + b->getRight() / 2 - default_width / 2;
	setX(x);
	float y = b->getBottom() - default_height * 2;
	setY(y);
}

string Paddle::getNameClass() {
	return "Paddle";
}

void Paddle::moveRight() {
	this->v = { default_v, 0 };
}

void Paddle::moveLeft() {
	this->v = { -default_v, 0 };
}

void Paddle::stopMoving() {
	this->v = { 0 , 0 };
}

void Paddle::setShape(float a)
{
	shape = new RectangleShape(Vector2f(default_width, default_height*a));
	setBackgroundColor(255, 0, 0);
}