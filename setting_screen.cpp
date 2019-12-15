#include "setting_screen.h"
#include "globals.h"

SettingScreen::SettingScreen(RenderWindow* window, Setting* setting) : Screen(window, setting) {}

SettingScreen::~SettingScreen() {}

void SettingScreen::processEvents() {
	setting->processEvents();

	switch (setting->getState()) {
	case 1:
		loop = false;
		nextScreen = EXIT;
		break;
	case 2:
		loop = false;
		nextScreen = MAIN_MENU;
		break;
	}
}
void SettingScreen::render() {
	setting->draw();
}