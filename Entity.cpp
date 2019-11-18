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

void Entity::setColor(int color) {
	if (color >= 0 && color <= 15) {
		this->color = color;
	}
}

void Entity::setBackgroundColor(int color_background) {
	if (color_background >= 0 && color_background <= 15) {
		this->color_background = color_background;
	}
}

int Entity::getColor() {
	return this->color;
}

int Entity::getBackgroundColor() {
	return this->color_background;
}