#include "paddle.h"

Paddle::Paddle(RenderWindow* window, Board* b, float x, float y, float width, float height) : MovingEntity(window, b, x, y) {
	shape = new RectangleShape(Vector2f(width, height));
	setX(x);
	setY(y);
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