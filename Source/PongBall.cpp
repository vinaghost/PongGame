#include "Pong.h"

Ball::Ball(int screenX, int screenY)
{
	shape.setRadius(r);
	shape.setOrigin(shape.getRadius(), shape.getRadius());
	x = screenX/2;
	y = screenY/2;
	v = sf::Vector2f();
}

void Ball::reflect(eDir dir)
{
	switch (dir)
	{
	case LEFT:
	case RIGHT:
		v.x*=-1.0;
		break;
	case UP:
	case DOWN:
		v.y*=-1.0;
		break;
	}
}
void Ball::randomDirection()
{
	idle = false;
	switch (rand() % 4)
	{
	case 0:
		v = sf::Vector2f(1.0,1.0)*(float)initspeed;
		break;
	case 1:
		v = sf::Vector2f(-1.0,1.0)*(float)initspeed;
		break;
	case 2:
		v = sf::Vector2f(1.0,-1.0)*(float)initspeed;
		break;
	case 3:
		v = sf::Vector2f(-1.0,-1.0)*(float)initspeed;
		break;
	}
}
void Ball::Move(int microsec)
{
	x += v.x*microsec/mSPF;
	y += v.y*microsec/mSPF;
}

void Ball::speedUp(float p){
	v*=(1+p);
}