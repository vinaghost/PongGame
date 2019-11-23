#include "Entity.h"

Entity::Entity(RenderWindow* window) : x(0), y(0), shape(NULL), window(window) {}

Entity::~Entity() {
	delete shape;
}

void Entity::setX(float x) {
	this->x = x;
}
void Entity::setY(float y) {
	this->y = y;
}
void Entity::setColor(int red, int green, int blue, int alpha) {
	if (red < 0) red = 0;
	else if (red > 255) red = 255;
	else this->color.r = red;

	if (green < 0) green = 0;
	else if (green > 255) green = 255;
	else this->color.g = green;

	if (blue < 0) blue = 0;
	else if (blue > 255) blue = 255;
	else this->color.b = blue;

	if (alpha < 0) alpha = 0;
	else if (alpha > 255) alpha = 255;
	else this->color.a = alpha;
}
void Entity::setBackgroundColor(int red, int green, int blue, int alpha) {
	if (red < 0) red = 0;
	else if (red > 255) red = 255;
	else this->color.r = red;

	if (green < 0) green = 0;
	else if (green > 255) green = 255;
	else this->color.g = green;

	if (blue < 0) blue = 0;
	else if (blue > 255) blue = 255;
	else this->color.b = blue;

	if (alpha < 0) alpha = 0;
	else if (alpha > 255) alpha = 255;
	else this->color.a = alpha;
}

float Entity::getX() {
	return this->x;
}
float Entity::getY() {
	return this->y;
}
Color Entity::getColor() {
	return this->color;
}
Color Entity::getBackgroundColor() {
	return this->color_background;
}

void Entity::draw() {
	window->draw(*shape);
}