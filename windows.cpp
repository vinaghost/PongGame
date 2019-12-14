#include "windows.h"
#include "globals.h"

#include "mainmenu_screen.h"
#include "game_screen.h"

#include "pause_screen.h"
#include "lose_screen.h"

#include "setting_screen.h"

Windows::Windows() : screen(MAIN_MENU) {
	renderWindow.create(VideoMode(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT), "Pong !", Style::Titlebar | Style::Close);
	renderWindow.setFramerateLimit(60);

	Screen* s;

	s = new MainMenuScreen(&renderWindow);
	screens.push_back(s);

	s = new GameScreen(&renderWindow);
	screens.push_back(s);

	s = new PauseScreen(&renderWindow);
	screens.push_back(s);

	s = new LoseScreen(&renderWindow);
	screens.push_back(s);

	s = new SettingScreen(&renderWindow);
	screens.push_back(s);
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