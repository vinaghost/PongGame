#pragma once
#include "screen.h"
#include "menu.h"
class WinScreen : public Screen {
protected:
	Menu* continueMenu;
	void processEvents();
	void render();
public:
	WinScreen(RenderWindow* window);
	virtual ~WinScreen();
};
