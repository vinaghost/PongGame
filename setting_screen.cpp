#include "setting_screen.h"
#include "globals.h"

SettingScreen::SettingScreen(RenderWindow* window) : Screen(window) {
	setting = new Setting(window, globals::SCREEN_WIDTH / 2 - 100, 200);
}

SettingScreen::~SettingScreen() {
	delete setting;
}

void SettingScreen::processEvents() {
	setting->processEvents();

	if (setting->getState()) {
		loop = false;
		nextScreen = MAIN_MENU;
	}
}
void SettingScreen::render() {
	setting->draw();
}

Setting* SettingScreen::getSetting() {
	return this->setting;
}