#pragma once
#include "entity.h"

using namespace sf;

enum eDir {
	LEFT = 1,
	UP = 2,
	DOWN = 3,
	RIGHT = 4
};

class Ball : public Entity {
private:
	Vector2f v;
	eDir direction;
	CircleShape shape;

	bool idle;
	int initspeed = 2; //Pixel per frame
	float radius;

public:
	Ball(RenderWindow* window);
	void setup(float x, float y);

	void reflect(eDir dir);

	void randomDirection();

	void speedUp(float percent);

	void update(int microsec);
};