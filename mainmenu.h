#pragma once
#include "screen.h"
#include "menu.h"

class MainMenu : public Screen {
private:
	Menu* mainMenu;
public:
	MainMenu(RenderWindow* window);
	virtual ~MainMenu();

	void setWindow(RenderWindow* window);
	int run();
};
