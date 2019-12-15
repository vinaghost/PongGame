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
class Paddle;

class Ball : public MovingEntity {
private:
	int state;
	const float radius;
	const int initspeed = 2; //Pixel per frame
	bool ingame;
	bool idle;

	Vector2f v_old;
	Entity* sticker;

	Clock clocker;
	Time nextTime;

public:
	Ball(RenderWindow* window, Board* b, float radius, Paddle* player);
	string getNameClass();

	void reset(Paddle* player);

	int getState();
	bool getIdle();

	void reflect(sides::Side side, bool dWall = false);

	void getStart();

	void speedUp(float percent);

	sides::Side getWallSide();

	const sides::Side getCollisionSide(Entity &other);
	void handleCollisions(std::vector<Entity*> others);
	void update(Int64 elapsedTime);

	void unfreeze();
	void freeze(Time time, Entity* sticker);
	void setShape(float a);
};