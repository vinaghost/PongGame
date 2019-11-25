#include "Entity.h"
Entity::Entity(RenderWindow* window) : shape(NULL), window(window) {}

Entity::~Entity() {
	delete shape;
}

void Entity::setX(float x) {
	this->shape->setPosition(x, this->shape->getPosition().y);
}
void Entity::setY(float y) {
	this->shape->setPosition(this->shape->getPosition().x, y);
}
void Entity::setColor(int red, int green, int blue, int alpha) {
	if (red < 0) red = 0;
	else if (red > 255) red = 255;

	if (green < 0) green = 0;
	else if (green > 255) green = 255;

	if (blue < 0) blue = 0;
	else if (blue > 255) blue = 255;

	if (alpha < 0) alpha = 0;
	else if (alpha > 255) alpha = 255;

	shape->setOutlineColor(Color(green, red, blue, alpha));
}
void Entity::setBackgroundColor(int red, int green, int blue, int alpha) {
	if (red < 0) red = 0;
	else if (red > 255) red = 255;

	if (green < 0) green = 0;
	else if (green > 255) green = 255;

	if (blue < 0) blue = 0;
	else if (blue > 255) blue = 255;

	if (alpha < 0) alpha = 0;
	else if (alpha > 255) alpha = 255;

	shape->setFillColor(Color(green, red, blue, alpha));
}

float Entity::getX() {
	return this->shape->getPosition().x;
}
float Entity::getY() {
	return this->shape->getPosition().y;
}
Color Entity::getColor() {
	return this->shape->getOutlineColor();
}
Color Entity::getBackgroundColor() {
	return this->shape->getFillColor();
}

void Entity::draw() {
	window->draw(*shape);
}