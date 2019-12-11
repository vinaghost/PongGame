#include "win_screen.h"
#include "globals.h"

#include <iostream>

WinScreen::WinScreen(RenderWindow* window) : Screen(window) {
	continueMenu = new Menu(window, globals::SCREEN_WIDTH / 2 - 100, 400);
}

WinScreen::~WinScreen() {
	delete continueMenu;
}

void WinScreen::processEvents() {
	continueMenu->processEvents();

	int choice = continueMenu->getChoice();
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
void WinScreen::render() {
	continueMenu->draw();
}