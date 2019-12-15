#pragma once
#include "screen.h"
#include "menu.h"
#include "caption.h"
class MainMenuScreen : public Screen {
private:
	Menu* mainMenu;
	Caption error;
protected:
	void processEvents();
	void reset();
	void render();
public:
	MainMenuScreen(RenderWindow* window, Setting* setting);
	virtual ~MainMenuScreen();
};
