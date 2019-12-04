#include "screen.h"

Screen::Screen(RenderWindow* window) : window(window), loop(true) {}

Screen::~Screen() {}

int Screen::run() {
	while (loop) {
		processEvents();
		update();

		window->clear();
		render();
		window->display();
	}
	return nextScreen;
}