#include "windows.h"

Windows::Windows(int width, int height) : width(width), height(height) {
	renderWindow.create(VideoMode(width, height), "Pong !", Style::Titlebar | Style::Close);
	renderWindow.setFramerateLimit(60);
}

Windows::~Windows() {}

void Windows::run() {
}