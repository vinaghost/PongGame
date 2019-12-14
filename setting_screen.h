#pragma once
#include "screen.h"
#include "setting.h"
class SettingScreen : public Screen {
private:
	Setting* setting;
protected:
	void processEvents();
	void render();
public:
	SettingScreen(RenderWindow* window);
	virtual ~SettingScreen();

	Setting* getSetting();
};
