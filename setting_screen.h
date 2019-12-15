#pragma once
#include "screen.h"
#include "setting.h"
class SettingScreen : public Screen {
protected:
	void processEvents();
	void render();
public:
	SettingScreen(RenderWindow* window);
	virtual ~SettingScreen();
};
