#pragma once

#include "WindowsGraphic.h"

class Entity
{
private:
	float x, y;
public:
	Entity(int screenX, int screenY);

	/**
	* Gán tọa độ x của Entity
	*
	* @note
	*
	*
	* @noreturn
	**/
	virtual void setX(float x);
	/**
	* Gán tọa độ y của Entity
	*
	* @note
	*
	*
	* @noreturn
	**/
	virtual void setY(float y);
	/**
	* Trả lại tọa độ x của Entity
	*
	* @note
	*
	*
	* @return (int) x
	**/
	float getX();
	/**
	* Trả lại tọa độ y của Entity
	*
	* @note
	*
	*
	* @return (int) y
	**/
	float getY();
};

