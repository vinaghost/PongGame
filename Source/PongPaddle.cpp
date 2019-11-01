#include "Pong.h"

Paddle::Paddle(int screenY)
{
	shape.setSize(sf::Vector2f(w,h));
	shape.setOrigin(shape.getSize()/2.f);
	y = originalY = screenY / 2;
}