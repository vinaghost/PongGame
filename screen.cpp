#include "screen.h"

#include <iostream>

Screen::Screen(RenderWindow* window) : window(window), loop(true) {
	setting = new Setting(window, 100, 100);
}

Screen::~Screen() {
	delete setting;
}

int Screen::run() {
	this->reset();

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