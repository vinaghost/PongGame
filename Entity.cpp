#include "Entity.h"



Entity::Entity(int screenX, int screenY): x(screenX / 2), y(screenY / 2)
{
}

void Entity::setX(float x)
{
	this->x = x;
}

void Entity::setY(float y)
{
	this->y = y;
}

float Entity::getX()
{
	return this->x;
}

float Entity::getY()
{
	return this->y;
}