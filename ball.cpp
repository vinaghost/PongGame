#include "ball.h"

Ball::Ball(RenderWindow* window) : Entity(window), radius(10), idle(true) {}

void Ball::setup(float x, float y) {
	shape.setRadius(radius);
	this->x = x;
	this->y = y;
	shape.setOrigin(x, y);
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
		v = sf::Vector2f(1.0, 1.0)*(float)initspeed;
		break;
	case 1:
		v = sf::Vector2f(-1.0, 1.0)*(float)initspeed;
		break;
	case 2:
		v = sf::Vector2f(1.0, -1.0)*(float)initspeed;
		break;
	case 3:
		v = sf::Vector2f(-1.0, -1.0)*(float)initspeed;
		break;
	}
}
void Ball::update(int microsec) {
	//setX(getX() + v.x * (microsec / mSPF));
	//setY(getY() + v.y * (microsec / mSPF));
}

void Ball::speedUp(float percent) {
	this->v *= (1 + percent);
}