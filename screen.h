#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
enum {
	EXIT = -1,
	MAIN_MENU,
	IN_GAME,
	PAUSE
};
class Screen {
protected:
	RenderWindow* window;
	int nextScreen;
	bool loop;
	virtual void processEvents();
	virtual void update();
	virtual void render();
	virtual void reset();
public:
	Screen(RenderWindow* window);
	virtual void setWindow(RenderWindow* window);
	int run();
	virtual ~Screen();
};
