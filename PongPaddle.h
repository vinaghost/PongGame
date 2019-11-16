#pragma once

#include <SFML/Graphics.hpp>
#include "WindowsGraphic.h"

class Paddle
{
private:
	float y;
	int originalY;

public:
	static int const speed = 10;
	static int const w = 10, h = 100;
	sf::RectangleShape shape;
	Paddle(int screenY);
	inline void reset();
	inline float getY();
	inline void moveUp(int timeInterval);
	inline void moveDown(int timeInterval);

};

