#include "pause_screen.h"
#include "globals.h"

#include <iostream>

PauseScreen::PauseScreen(RenderWindow* window, Setting* setting) : Screen(window, setting) {
	pauseMenu = new Menu(window, globals::SCREEN_WIDTH / 2 - 100, 300);
	pauseMenu->addButtons("Continue");
	pauseMenu->addButtons("Back to Mainmenu");
	pauseMenu->initMenu(80);
}

PauseScreen::~PauseScreen() {
	delete pauseMenu;
}

void PauseScreen::processEvents() {
	pauseMenu->processEvents();

	int choice = pauseMenu->getChoice();
	switch (choice) {
	case 0:
		loop = false;
		nextScreen = IN_GAME;
		break;
	case 1:
		loop = false;
		nextScreen = MAIN_MENU;
		break;
	}

	if (choice == pauseMenu->getCount()) {
		loop = false;
		nextScreen = EXIT;
	}
}
void PauseScreen::render() {
	pauseMenu->draw();
}