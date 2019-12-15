#include "lose_screen.h"
#include "globals.h"

#include <iostream>

LoseScreen::LoseScreen(RenderWindow* window, Setting* setting) : Screen(window, setting) {
	continueMenu = new Menu(window, globals::SCREEN_WIDTH / 2 - 100, 300);
	continueMenu->addButtons("Play again");
	continueMenu->addButtons("Back to Mainmenu");
	continueMenu->initMenu(80);
}

LoseScreen::~LoseScreen() {
	delete continueMenu;
}

void LoseScreen::processEvents() {
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
	if (choice == continueMenu->getCount()) {
		loop = false;
		nextScreen = EXIT;
	}
}
void LoseScreen::render() {
	continueMenu->draw();
}