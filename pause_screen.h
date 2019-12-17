#pragma once
#include "screen.h"
#include "menu.h"
#include "setting.h"
class PauseScreen : public Screen {
private:
	Menu* pauseMenu;
	Setting* setting;
protected:
	void processEvents();
	void render();
public:
	PauseScreen(RenderWindow* window, Setting* setting);
	virtual ~PauseScreen();
};
