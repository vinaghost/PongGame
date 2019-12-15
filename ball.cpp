#include "ball.h"
#include "paddle.h"
#include "freezeBall_item.h"
#include "Brick.h"
#include "bigball.h"
#include "bigpaddle.h"
#include "smallball.h"
#include "smallpaddle.h"
#include "item.h"
#include <iostream>
Ball::Ball(RenderWindow* window, Board* b, float radius, Paddle* player) : MovingEntity(window, b, b->getLeft() / 2 + b->getRight() / 2 - radius, player->getTop() - radius * 3), idle(true), radius(radius), sticker(player), state(0), ingame(false), combo_score(1) {
	srand((unsigned int)time(NULL));

	shape = new CircleShape(radius);

	setX(b->getLeft() / 2 + b->getRight() / 2 - radius);
	setY(player->getTop() - radius * 3);

	v = v_old = { 0 , 0 };

	buffer.loadFromFile("Resources/ball_hit.wav");
	sound.setBuffer(buffer);
}

string Ball::getNameClass() {
	return "Ball";
}
void Ball::reset(Paddle* player) {
	MovingEntity::reset();
	idle = true;
	sticker = player;
	v = v_old = { 0, 0 };
	state = 0;
	combo_score = 1;
}
bool Ball::getIdle() {
	return v.x == 0 && v.y == 0;
}
int Ball::getState() {
	return this->state;
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
void Ball::getStart() {
	idle = false;
	unfreeze();

	switch (rand() % 2) {
	case 0:
		v = Vector2f(1.0, -1.0) * (float)initspeed;
		break;
	case 1:
		v = Vector2f(-1.0, -1.0) * (float)initspeed;
		break;
	}
}

void Ball::speedUp(float percent) {
	this->v *= (1 + percent);
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
const sides::Side Ball::getCollisionSide(Entity &other) {
	float amtRight, amtLeft, amtTop, amtBottom;

	amtRight = this->getRight() - other.getLeft();
	float lowest = abs(amtRight);

	amtLeft = this->getLeft() - other.getRight();
	if (lowest > abs(amtLeft)) lowest = abs(amtLeft);

	amtTop = this->getTop() - other.getBottom();
	if (lowest > abs(amtTop)) lowest = abs(amtTop);

	amtBottom = this->getBottom() - other.getTop();
	if (lowest > abs(amtBottom)) lowest = abs(amtBottom);

	// nào nhỏ nhất thì mình đang đụng nó .-.

	return lowest == abs(amtRight) ? sides::RIGHT :
		lowest == abs(amtLeft) ? sides::LEFT :
		lowest == abs(amtBottom) ? sides::BOTTOM :
		sides::TOP;
}
void Ball::handleCollisions(std::vector<Entity*> others) {
	sides::Side collisionSide;
	bool dWall = false;
	bool dEntity = false;

	collisionSide = getWallSide();
	if (collisionSide != sides::NONE) {
		switch (collisionSide) {
		case sides::BOTTOM:
			state = 1;
			return;
		case sides::LEFT:
		case sides::RIGHT:
		case sides::TOP:
			dWall = true;
		}
	}

	for (size_t i = 0; i < others.size(); i++) {
		if (this->isIntersect(*others.at(i))) {
			collisionSide = getCollisionSide(*others.at(i));
			if (collisionSide != sides::NONE) {
				dEntity = true;
				switch (collisionSide) {
				case sides::TOP: {
					setY(others.at(i)->getBottom() + 1);
					break;
				}
				case sides::BOTTOM: {
					setY(others.at(i)->getY() - this->shape->getGlobalBounds().height - 1);
					break;
				}
				case sides::LEFT: {
					setX(others.at(i)->getRight() + 1);
					break;
				}
				case sides::RIGHT: {
					setX(others.at(i)->getX() - this->shape->getGlobalBounds().width - 1);
					break;
				}
				}
				reflect(collisionSide, dWall);
				sound.play();
				if (others.at(i)->getNameClass() == "Paddle") {
					if (!idle) {
						speedUp(0.1f);
						freeze(seconds(0.05f), others.at(i));
					}
				}
				else if (others.at(i)->getNameClass() == "freeze")
				{
					static_cast<freezeBall_item*>(others.at(i))->active(this);
				}
				else if (others.at(i)->getNameClass() == "Brick")
				{
					static_cast<Brick*>(others.at(i))->active(this);
					setScore(getScore() + 2 * combo_score);
				}
				else if (others.at(i)->getNameClass() == "bigball")
				{
					static_cast<BigBall*>(others.at(i))->active(this);
				}
				else if (others.at(i)->getNameClass() == "smallball")
				{
					static_cast<smallball*>(others.at(i))->active(this);
				}
				else if (others.at(i)->getNameClass() == "bigpaddle")
				{
					static_cast<bigpaddle*>(others.at(i))->active(others[0]);
				}
				else if (others.at(i)->getNameClass() == "smallpaddle")
				{
					static_cast<smallpaddle*>(others.at(i))->active(others[0]);
				}
			}
		}
	}

	if (dWall && !dEntity) {
		reflect(collisionSide);
		sound.play();
	}
}

void Ball::update(Int64 elapsedTime) {
	if (idle && sticker) {
		if (nextTime < clocker.getElapsedTime() && ingame) {
			unfreeze();
		}
		else {
			this->v = static_cast<Paddle*>(sticker)->getV();
		}
	}
	MovingEntity::update(elapsedTime);
}
void Ball::freeze(Time time, Entity* sticker) {
	idle = true;
	v_old = v;
	ingame = true;
	this->sticker = sticker;
	clocker.restart();
	nextTime = clocker.getElapsedTime() + time;
}
void Ball::unfreeze() {
	idle = false;

	ingame = false;
	sticker = NULL;
	v = v_old;
}
void Ball::setShape(float a)
{
	static_cast<CircleShape*>(shape)->setRadius(radius*a);
}
void Ball::setSetting(Setting* setting) {
	this->setting = setting;
}
void Ball::setScore(int score) {
	setting->setScore(score);
}
int Ball::getScore() {
	return setting->getScore();
}