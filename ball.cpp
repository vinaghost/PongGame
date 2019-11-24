#include "ball.h"

Ball::Ball(RenderWindow* window, Board* b) : MovingEntity(window, b), idle(true) {
	srand((unsigned int)time(NULL));
	shape = new CircleShape;
}

string Ball::getNameClass() {
	return "Ball";
}
void Ball::setup(float x, float y, float radius) {
	static_cast<CircleShape*>(shape)->setRadius(radius);
	setX(x);
	setY(y);
}
bool Ball::getIdle() {
	return this->idle;
}
void Ball::reflect(eDir dir) {
	switch (dir) {
	case LEFT:
	case RIGHT:
		v.x *= -1.0;
		break;
	case UP:
	case DOWN:
		v.y *= -1.0;
		break;
	}
}
void Ball::randomDirection() {
	idle = false;
	switch (rand() % 4) {
	case 0:
		v = Vector2f(1.0, 1.0) * (float)initspeed;
		break;
	case 1:
		v = Vector2f(-1.0, 1.0)*(float)initspeed;
		break;
	case 2:
		v = Vector2f(1.0, -1.0)*(float)initspeed;
		break;
	case 3:
		v = Vector2f(-1.0, -1.0)*(float)initspeed;
		break;
	}
}

void Ball::speedUp(float percent) {
	this->v *= (1 + percent);
}
eDir Ball::getWall() {
	if (shape->getGlobalBounds().left <= b->getLeft()) {
		return LEFT;
	}

	if (shape->getGlobalBounds().left + shape->getGlobalBounds().width >= b->getRight()) {
		return RIGHT;
	}

	if (shape->getGlobalBounds().top <= b->getTop()) {
		return UP;
	}

	if (shape->getGlobalBounds().top + shape->getGlobalBounds().height >= b->getBottom()) {
		return DOWN;
	}
	return NONE;
}
void Ball::update(Int64 elapsedTime) {
	eDir dir = getWall();

	if (dir) {
		reflect(dir);
	}

	MovingEntity::update(elapsedTime);
}