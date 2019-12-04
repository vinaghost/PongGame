#include "windows.h"
#include "globals.h"

#include "game.h"
#include "mainmenu.h"
Windows::Windows() : screen(0) {
	renderWindow.create(VideoMode(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT), "Pong !", Style::Titlebar | Style::Close);
	renderWindow.setFramerateLimit(60);
}

Windows::~Windows() {}

void Windows::run() {
	MainMenu* mMenu = new MainMenu(&renderWindow);
	Game* g = new Game(&renderWindow);

	screens.push_back(mMenu);
	screens.push_back(g);

	while (screen >= 0) {
		screen = screens[screen]->run();
	}
}