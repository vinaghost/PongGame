#include "entity.h"
Entity::Entity(RenderWindow* window, float x, float y) : shape(NULL), window(window), x(x), y(y) {}

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

	shape->setFillColor(Color(red, green, blue, alpha));
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
bool Entity::isIntersect(Entity &other) {
	return this->shape->getGlobalBounds().intersects(other.shape->getGlobalBounds());
}

const sides::Side Entity::getCollisionSide(Entity &other) {
	float amtRight, amtLeft, amtTop, amtBottom;

	amtRight = this->shape->getGlobalBounds().left + this->shape->getGlobalBounds().width - other.shape->getGlobalBounds().left;
	float lowest = abs(amtRight);

	amtLeft = this->shape->getGlobalBounds().left - other.shape->getGlobalBounds().left + other.shape->getGlobalBounds().width;
	if (lowest > abs(amtLeft)) lowest = abs(amtLeft);

	amtTop = this->shape->getGlobalBounds().top - other.shape->getGlobalBounds().top + other.shape->getGlobalBounds().height;
	if (lowest > abs(amtTop)) lowest = abs(amtTop);

	amtBottom = this->shape->getGlobalBounds().top + this->shape->getGlobalBounds().height - other.shape->getGlobalBounds().top;
	if (lowest > abs(amtBottom)) lowest = abs(amtBottom);

	// nào nhỏ nhất thì mình đang đụng nó .-.

	return lowest == abs(amtRight) ? sides::RIGHT :
		lowest == abs(amtLeft) ? sides::LEFT :
		lowest == abs(amtBottom) ? sides::BOTTOM :
		sides::TOP;
}