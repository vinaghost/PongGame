#include "screen.h"

#include <iostream>

Screen::Screen(RenderWindow* window, Setting* setting) : window(window), setting(setting), loop(true) {
	texTitle.loadFromFile("Resources/Title.png");
	spTitle.setTexture(texTitle, true);
	spTitle.setPosition(300, 80);
}

Screen::~Screen() {
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