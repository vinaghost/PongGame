#pragma once
#include "menu.h"




class MenuMain : public Menu
{
private:
	int choice;
	Event event;
public:
	MenuMain(RenderWindow* window, float x, float y);
	void show();
	void update();
	/**
	* Trả về lựa chọn item
	*
	* @note
	*
	*
	* @return (int) item được chọn
	**/
	int getChoice();
};
