#include "windows.h"
#include "globals.h"

#include "mainmenu_screen.h"
#include "game_screen.h"
#include "pause_screen.h"

Windows::Windows() : screen(MAIN_MENU) {
	renderWindow.create(VideoMode(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT), "Pong !", Style::Titlebar | Style::Close);
	renderWindow.setFramerateLimit(60);

	MainMenuScreen* mainMenuScreen = new MainMenuScreen(&renderWindow);
	screens.push_back(mainMenuScreen);

	GameScreen* gameScreen = new GameScreen(&renderWindow);
	screens.push_back(gameScreen);

	PauseScreen* pauseScreen = new PauseScreen(&renderWindow);
	screens.push_back(pauseScreen);
}

Windows::~Windows() {
	for (auto i : screens) {
		delete i;
	}
}

void Windows::run() {
	while (screen != EXIT) {
		screen = screens[screen]->run();
	}
}