#pragma once
#include "screen.h"
#include "menu.h"
class LoseScreen : public Screen {
protected:
	Menu* continueMenu;
	void processEvents();
	void render();
public:
	LoseScreen(RenderWindow* window);
	virtual ~LoseScreen();
};
