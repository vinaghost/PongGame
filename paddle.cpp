#include "paddle.h"

Paddle::Paddle(RenderWindow* window, Board* b, winners::side side) : MovingEntity(window, b, side == winners::LEFT ? b->getLeft() + 10 : b->getRight() - default_width - 10, b->getTop() / 2 + b->getBottom() / 2 - default_height / 2) {
	shape = new RectangleShape(Vector2f(default_width, default_height));

	setX(side == winners::LEFT ? b->getLeft() + 10 : b->getRight() - default_width - 10);
	setY(b->getTop() / 2 + b->getBottom() / 2 - default_height / 2);
}

string Paddle::getNameClass() {
	return "Paddle";
}

void Paddle::moveUp() {
	this->v = { 0 , -default_v };
}

void Paddle::moveDown() {
	this->v = { 0 , default_v };
}

void Paddle::stopMoving() {
	this->v = { 0 , 0 };
}