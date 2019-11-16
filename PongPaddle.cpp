#include "PongPaddle.h"

Paddle::Paddle(int screenY)
{
	shape.setSize(sf::Vector2f(w, h));
	shape.setOrigin(shape.getSize() / 2.f);
	y = originalY = screenY / 2;
}

inline void Paddle::reset()
{
	y = originalY;
}

inline float Paddle::getY()
{
	return y;
}

inline void Paddle::moveUp(int timeInterval)
{
	y -= (speed * timeInterval / mSPF);
}

inline void Paddle::moveDown(int timeInterval)
{
	y += (speed * timeInterval / mSPF);
}