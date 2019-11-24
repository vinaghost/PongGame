#pragma once
#include "movingentity.h"

enum eDir {
	NONE,
	LEFT,
	UP,
	DOWN,
	RIGHT
};

class Ball : public MovingEntity {
private:
	bool idle;
	const int initspeed = 2; //Pixel per frame

public:
	Ball(RenderWindow* window, Board* b);
	string getNameClass();

	void setup(float x, float y, float radius);

	bool getIdle();

	void reflect(eDir dir);

	void randomDirection();

	void speedUp(float percent);

	eDir getWall();
	void update(Int64 elapsedTime);
};