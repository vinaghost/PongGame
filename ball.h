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
	winner::side winner;
	const float radius;
	const int initspeed = 2; //Pixel per frame
	bool idle;

	Vector2f v_old;
	Entity* sticker;

	Clock clocker;
	Time nextTime;

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

	const sides::Side getCollisionSide(Entity &other);
	void handleCollisions(std::vector<Entity*> others);
	void update(Int64 elapsedTime);

	void unfreeze();
	void freeze(Time time, Entity* sticker);
};