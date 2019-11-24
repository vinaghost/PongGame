#include "movingentity.h"

MovingEntity::MovingEntity(RenderWindow* window, Board* b) : Entity(window), b(b) {
}

MovingEntity::~MovingEntity() {
}

void MovingEntity::setX(float x) {
	if (x < this->b->getLeft()) x = this->b->getLeft();
	else if (x > this->b->getRight()) x = this->b->getRight();

	Entity::setX(x);
}

void MovingEntity::setY(float y) {
	if (y < this->b->getTop()) y = this->b->getTop();
	else if (y > this->b->getBottom()) y = this->b->getBottom();

	Entity::setY(y);
}

void MovingEntity::update(Int64 elapsedTime) {
	setX(getX() + v.x * elapsedTime / mSPF);
	setY(getY() + v.y * elapsedTime / mSPF);
}