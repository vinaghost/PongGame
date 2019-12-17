#pragma once
#include <SFML/Graphics.hpp>
#include "setting.h"

using namespace sf;
enum {
	EXIT = -1,
	MAIN_MENU,
	IN_GAME,
	PAUSE,
	LOSE,
	SETTING,
	STAT
};
class Screen {
protected:

	Texture texTitle;
	Sprite spTitle;

	RenderWindow* window;
	Setting* setting;
	Event event;
	int nextScreen;
	bool loop;
	virtual void processEvents();
	virtual void update();
	virtual void render();
	virtual void reset();
public:
	Screen(RenderWindow* window, Setting* setting);
	virtual void setWindow(RenderWindow* window);
	int run();
	virtual ~Screen();

	void setSetting(Setting* setting);
};
