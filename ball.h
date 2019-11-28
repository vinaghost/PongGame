#pragma once
#include "movingentity.h"

#include <vector>
namespace winner {
	enum side {
		NONE,
		LEFT,
		RIGHT
	};
};

class Ball : public MovingEntity {
private:
	bool idle;
	winner::side winner;
	const float radius;
	const int initspeed = 2; //Pixel per frame

public:
	Ball(RenderWindow* window, Board* b, float radius);
	string getNameClass();

	void reset();

	winner::side getWinner();
	bool getIdle();

	void reflect(sides::Side side, bool dWall = false);

	void randomDirection();

	void speedUp(float percent);
	sides::Side getWallSide();

	void handleCollisions(std::vector<Entity*> others);
	void update(Int64 elapsedTime);
};