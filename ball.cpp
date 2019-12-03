#include "ball.h"
#include <iostream>
Ball::Ball(RenderWindow* window, Board* b, float radius) : MovingEntity(window, b, b->getLeft() / 2 + b->getRight() / 2 - radius, b->getTop() / 2 + b->getBottom() / 2 - radius), idle(true), radius(radius) {
	srand((unsigned int)time(NULL));

	shape = new CircleShape(radius);

	setX(b->getLeft() / 2 + b->getRight() / 2 - radius);
	setY(b->getTop() / 2 + b->getBottom() / 2 - radius);
}

string Ball::getNameClass() {
	return "Ball";
}
void Ball::reset() {
	MovingEntity::reset();
	v = { 0, 0 };
	idle = true;
	winner = winner::NONE;
}
bool Ball::getIdle() {
	return this->idle;
}
winner::side Ball::getWinner() {
	return this->winner;
}
void Ball::reflect(sides::Side side, bool dWall) {
	if (dWall) {
		v.x *= -1.0;
		v.y *= -1.0;
	}
	else {
		switch (side) {
		case sides::LEFT:
		case sides::RIGHT:
			v.x *= -1.0;
			break;
		case sides::TOP:
		case sides::BOTTOM:
			v.y *= -1.0;
			break;
		}
	}
}
void Ball::randomDirection() {
	idle = false;
	switch (rand() % 4) {
	case 0:
		v = Vector2f(1.0, 1.0) * (float)initspeed;
		break;
	case 1:
		v = Vector2f(-1.0, 1.0) * (float)initspeed;
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

void Ball::speedDown(float percent)
{
	this->v *= (1 - percent);
}

sides::Side Ball::getWallSide() {
	if (shape->getGlobalBounds().left <= b->getLeft() + 1) {
		return sides::LEFT;
	}

	if (shape->getGlobalBounds().left + shape->getGlobalBounds().width >= b->getRight()) {
		return sides::RIGHT;
	}

	if (shape->getGlobalBounds().top <= b->getTop()) {
		return sides::TOP;
	}

	if (shape->getGlobalBounds().top + shape->getGlobalBounds().height >= b->getBottom()) {
		return sides::BOTTOM;
	}
	return sides::NONE;
}
void Ball::handleCollisions(std::vector<Entity*> others) {
	sides::Side collisionSide;
	bool dWall = false;

	collisionSide = getWallSide();
	if (collisionSide != sides::NONE) {
		switch (collisionSide) {
		case sides::LEFT:
			winner = winner::RIGHT;
			return;
		case sides::RIGHT:
			winner = winner::LEFT;
			return;
		default:
			reflect(collisionSide);
		}

		dWall = true;
	}

	for (size_t i = 0; i < others.size(); i++) {
		if (this->isIntersect(*others.at(i))) {
			collisionSide = Entity::getCollisionSide(*others.at(i));
			if (collisionSide != sides::NONE) {
				if (others.at(i)->getNameClass() == "Paddle") {
					speedUp(0.1f);
				}

				reflect(collisionSide, dWall);
			}
		}
	}
}

void Ball::update(Int64 elapsedTime) {
	MovingEntity::update(elapsedTime);
}