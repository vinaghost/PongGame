#include "Entity.h"



Entity::Entity(int x, int y) : x(x), y(y) {}

void Entity::setX(double x) {
	this->x = x;
}

void Entity::setY(double y)
{
	this->y = y;
}

double Entity::getX()
{
	return this->x;
}

double Entity::getY()
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