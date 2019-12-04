#include "mainmenu.h"

MainMenu::MainMenu(RenderWindow* window) : Screen(window) {
}

MainMenu::~MainMenu() {
}

void MainMenu::setWindow(RenderWindow* window) {
	this->window = window;
}