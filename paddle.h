#pragma once
#include "movingentity.h"
class Paddle : public MovingEntity {
private:
	const float default_v = 15;
public:
	Paddle(RenderWindow* window, Board* b, float x, float y, float width, float height);
	string getNameClass();

	void moveUp();
	void moveDown();
	void stopMoving();
};
