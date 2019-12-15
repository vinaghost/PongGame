#include "windows.h"
#include "globals.h"

#include "mainmenu_screen.h"
#include "game_screen.h"

#include "pause_screen.h"
#include "lose_screen.h"

#include "setting_screen.h"
#include "stat_screen.h"

Windows::Windows() : screen(MAIN_MENU) {
	renderWindow.create(VideoMode(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT), "Pong !", Style::Titlebar | Style::Close);
	renderWindow.setFramerateLimit(60);

	setting = new Setting(&renderWindow, 100, 100);
	Screen* s;

	s = new MainMenuScreen(&renderWindow, setting);
	screens.push_back(s);

	s = new GameScreen(&renderWindow, setting);
	screens.push_back(s);

	s = new PauseScreen(&renderWindow, setting);
	screens.push_back(s);

	s = new LoseScreen(&renderWindow, setting);
	screens.push_back(s);

	s = new SettingScreen(&renderWindow, setting);
	screens.push_back(s);

	s = new StatScreen(&renderWindow, setting);
	screens.push_back(s);

	music.openFromFile("Resources/background.ogg");
}

Windows::~Windows() {
	for (auto &i : screens) {
		delete i;
	}
}

void Windows::run() {
	setting->load();
	music.play();
	music.setLoop(true);
	while (screen != EXIT) {
		screen = screens[screen]->run();
	}
	music.stop();
	setting->save();
}