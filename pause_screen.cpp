#include "pause_screen.h"
#include "globals.h"

#include <iostream>

PauseScreen::PauseScreen(RenderWindow* window) : Screen(window) {
	pauseMenu = new Menu(window, globals::SCREEN_WIDTH / 2 - 100, 100);
	pauseMenu->addButtons("Continue");
	pauseMenu->addButtons("Exit");
	pauseMenu->initMenu(100);
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
}
void PauseScreen::render() {
	pauseMenu->draw();
}