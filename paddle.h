#pragma once
#include "movingentity.h"
#include "globals.h"
class Paddle : public MovingEntity {
private:
	const float default_width = 10;
	const float default_height = 100;

	const float default_v = 15;

	winners::side side;

public:
	Paddle(RenderWindow* window, Board* b, winners::side side);
	string getNameClass();

	void moveUp();
	void moveDown();
	void stopMoving();

	winners::side getSide();
};
