#pragma once
#include "entity.h"
#include "board.h"

#define FPS (float)60.0
float const mSPF = (float)1000000.0f / FPS;

class MovingEntity : public Entity {
protected:
	Vector2f v;

	Board* b;
public:
	MovingEntity(RenderWindow* window, Board* b, float x, float y);
	virtual ~MovingEntity();

	virtual void reset();

	void setX(float x);
	void setY(float y);

	virtual void update(Int64 elapsedTime);
};
