#include "screen.h"

#include <iostream>

Screen::Screen(RenderWindow* window) : window(window), loop(true) {}

Screen::~Screen() {}

int Screen::run(bool reset) {
	if (reset) this->reset();
	loop = true;
	while (loop) {
		processEvents();
		update();

		window->clear();
		render();
		window->display();
	}
	return nextScreen;
}

void Screen::setWindow(RenderWindow *window) {
	this->window = window;
}

void Screen::processEvents() {}
void Screen::update() {}
void Screen::render() {}
void Screen::reset() {}