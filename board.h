#pragma once
#include "entity.h"
class Board : public Entity {
private:
	RectangleShape midLine;
	const float default_width = 400.f;
	const float default_height = 500.f;
	const float default_x = 400.f - default_width / 2;
	const float default_y = 50.f;

public:
	Board(RenderWindow* window);
	/**
	* Trả lại tên class
	*
	* @note
	*
	*
	* @noreturn (string) tên Class
	**/
	string getNameClass();
	/**
	* Trả lại tung độ trên
	*
	* @note
	*
	*
	* @return (float) top
	**/
	float getTop();

	/**
	* Trả lại tung độ dưới
	*
	* @note
	*
	*
	* @return (float) bottom
	**/
	float getBottom();

	/**
	* Trả lại hoành độ phải
	*
	* @note
	*
	*
	* @return (float) right
	**/
	float getRight();

	/**
	* Trả lại hoành độ trái
	*
	* @note
	*
	*
	* @return (float) left
	**/
	float getLeft();

	void draw();
};
