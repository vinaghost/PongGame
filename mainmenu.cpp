#include "mainmenu.h"
#include "globals.h"

MainMenu::MainMenu(RenderWindow* window) : Screen(window) {
	mainMenu = new Menu(window, globals::SCREEN_WIDTH / 2 - 100, 100);
	mainMenu->addButtons("Play");
	mainMenu->addButtons("Exit");
	mainMenu->initMenu(100);
}

MainMenu::~MainMenu() {
}

void MainMenu::setWindow(RenderWindow* window) {
	this->window = window;
}
void MainMenu::processEvents() {
	this->mainMenu->processEvents();
}
void MainMenu::update() {
	int choice = mainMenu->getChoice();
	switch (choice) {
	case 0:
		nextScreen = 1;
	}
	if (nextScreen != -1) loop = false;
}
void MainMenu::render() {
	this->mainMenu->draw();
}