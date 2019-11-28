#pragma once
#include "entity.h"
class Board : public Entity {
private:
	RectangleShape midLine;
public:
	Board(RenderWindow* window, float x, float y, float width, float height);
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
