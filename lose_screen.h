#pragma once
#include "screen.h"
#include "menu.h"
class LoseScreen : public Screen {
private:
	Menu* continueMenu;
protected:
	void processEvents();
	void render();
public:
	LoseScreen(RenderWindow* window, Setting* setting);
	virtual ~LoseScreen();
};
