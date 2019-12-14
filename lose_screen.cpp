#include "lose_screen.h"
#include "globals.h"

#include <iostream>

LoseScreen::LoseScreen(RenderWindow* window) : Screen(window) {
	continueMenu = new Menu(window, globals::SCREEN_WIDTH / 2 - 100, 400);
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
}
void LoseScreen::render() {
	continueMenu->draw();
}