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
	virtual void processEvents() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void reset() = 0;
public:
	Screen(RenderWindow* window);
	virtual void setWindow(RenderWindow* window) = 0;
	int run(bool reset = 0);
	virtual ~Screen();
};
