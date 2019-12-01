#pragma once
#include "menu.h"


class MenuMain : public Menu
{
private:
	RenderWindow* window;
	float x, y;
public:
	MenuMain(RenderWindow* window, float x, float y);
	void show();
	void update();
	
};

