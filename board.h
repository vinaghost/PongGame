#pragma once
#include "entity.h"
#include "globals.h"
class Board : public Entity {
private:
	const float default_width = 600.f;
	const float default_height = 500.f;
	const float default_x = globals::SCREEN_WIDTH / 2 - default_width / 2;
	const float default_y = globals::SCREEN_HEIGHT / 2 - default_height / 2 + 50;

	Text text;
	Font font;
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

	void draw();
};
