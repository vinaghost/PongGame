#include "movingentity.h"

#include <iostream>
MovingEntity::MovingEntity(RenderWindow* window, Board* b, float x, float y) : Entity(window, x, y), b(b) {
}

MovingEntity::~MovingEntity() {
}

void MovingEntity::reset() {
	setX(x);
	setY(y);
}
void MovingEntity::setX(float x) {
	if (x < this->b->getLeft()) x = this->b->getLeft();
	else if (x + this->shape->getLocalBounds().width > this->b->getRight()) x = this->b->getRight() - this->shape->getLocalBounds().width;

	Entity::setX(x);
}

void MovingEntity::setY(float y) {
	if (y < this->b->getTop()) y = this->b->getTop();
	else if (y + this->shape->getLocalBounds().height > this->b->getBottom()) y = this->b->getBottom() - this->shape->getLocalBounds().height;

	Entity::setY(y);
}

void MovingEntity::update(Int64 elapsedTime) {
	setX(getX() + v.x * elapsedTime / mSPF);
	setY(getY() + v.y * elapsedTime / mSPF);
}