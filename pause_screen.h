#pragma once
#include "screen.h"
#include "menu.h"
class PauseScreen : public Screen {
private:
	Menu* pauseMenu;
protected:
	void processEvents();
	void render();
public:
	PauseScreen(RenderWindow* window);
	virtual ~PauseScreen();
};
