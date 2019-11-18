#pragma once

#include "WindowsGraphic.h"

#include <string>
using namespace std;

class Entity
{
private:
	float x, y;
	int color, color_background;
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

	/**
	* Trả lại tên class
	*
	* @note
	*
	*
	* @noreturn (string) tên Class
	**/
	virtual string getNameClass() = 0;

	/**
	* Gán màu của Entity
	*
	* @note
	*
	*
	* @noreturn
	**/
	void setColor(int color);

	/**
	* Gán màu nền của Entity
	*
	* @note
	*
	*
	* @noreturn
	**/
	void setBackgroundColor(int color_background);

	/**
	* Trả lại màu của Entity
	*
	* @note
	*
	*
	* @return (int) color
	**/
	int getColor();

	/**
	* Trả lại màu nền của Entity
	*
	* @note
	*
	*
	* @return (int) color_background
	**/
	int getBackgroundColor();

};

