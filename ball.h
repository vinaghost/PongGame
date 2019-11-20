#pragma once
#include "entity.h"

enum eDir
{
	LEFT = 1,
	UP = 2,
	DOWN = 3,
	RIGHT = 4
};


class Ball : public Entity
{
private:
	sf::Vector2f v;
	float x, y;
	eDir direction;

public:
	bool idle = true;
	static int const initspeed = 2; //Pixel per frame
	static int const r = 10;
	sf::CircleShape shape;
	Ball(int screenX, int screenY);
	void speedUp(float);
	void reflect(eDir);
	inline float getX();
	inline float getY();
	void randomDirection();
	void Move(int microsec);
};