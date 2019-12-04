#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Screen {
protected:
	RenderWindow* window;
public:
	Screen(RenderWindow* window);
	virtual void setWindow(RenderWindow* window) = 0;
	virtual int run() = 0;
	virtual ~Screen();
};
