#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
enum {
	MAIN_MENU,
	PlAY_GAME,
};
class Screen {
protected:
	RenderWindow* window;
	int nextScreen;
	bool loop;
	virtual void processEvents() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
public:
	Screen(RenderWindow* window);
	virtual void setWindow(RenderWindow* window) = 0;
	int run();
	virtual ~Screen();
};
