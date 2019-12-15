#include "mainmenu_screen.h"
#include "globals.h"

MainMenuScreen::MainMenuScreen(RenderWindow* window, Setting* setting) : Screen(window, setting) {
	mainMenu = new Menu(window, globals::SCREEN_WIDTH / 2 - 100, 200);
	mainMenu->addButtons("Play");
	mainMenu->addButtons("Setting");
	mainMenu->addButtons("Stat");
	mainMenu->addButtons("Exit");
	mainMenu->initMenu(80);
}

MainMenuScreen::~MainMenuScreen() {
	delete mainMenu;
}

void MainMenuScreen::processEvents() {
	mainMenu->processEvents();

	int choice = mainMenu->getChoice();
	switch (choice) {
	case 0:
		if (setting->getLoaded()) {
			loop = false;
			nextScreen = IN_GAME;
		}
		break;
	case 1:
		loop = false;
		nextScreen = SETTING;
		break;
	case 2:
		loop = false;
		nextScreen = STAT;
		break;
	case 3:
		loop = false;
		nextScreen = EXIT;
		break;
	}

	if (choice == mainMenu->getCount()) {
		loop = false;
		nextScreen = EXIT;
	}
}
void MainMenuScreen::render() {
	mainMenu->draw();
}