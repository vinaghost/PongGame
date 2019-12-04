#pragma once
#include "screen.h"
#include "menu.h"

class MainMenu : public Screen {
private:
	Menu* mainMenu;
protected:
	void processEvents();
	void update();
	void render();
public:
	MainMenu(RenderWindow* window);
	virtual ~MainMenu();

	void setWindow(RenderWindow* window);
};
