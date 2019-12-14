#pragma once
#include "movingentity.h"
#include "globals.h"

const float default_width = 100.0f;
const float default_height = 10.0f;

class Paddle : public MovingEntity {
private:

	const float default_v = 15;

public:
	Paddle(RenderWindow* window, Board* b);
	string getNameClass();

	void moveRight();
	void moveLeft();
	void stopMoving();
};
