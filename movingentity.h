#pragma once
#include "entity.h"

class MovingEntity : public Entity {
private:
	Vector2f v;

public:
	MovingEntity(RenderWindow* window);
	virtual ~MovingEntity();
};
