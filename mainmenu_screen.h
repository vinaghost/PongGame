#pragma once
#include "screen.h"
#include "menu.h"
class MainMenuScreen : public Screen {
private:
	Menu* mainMenu;
protected:
	void processEvents();
	void render();
public:
	MainMenuScreen(RenderWindow* window, Setting* setting);
	virtual ~MainMenuScreen();
};
