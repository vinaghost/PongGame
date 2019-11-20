#pragma once
#include <SFML/Graphics.hpp>

#define FPS 60.0

double const mSPF = 1000000.0 / FPS;

class Windows {
protected:
	int width, height;
	sf::RenderWindow renderWindow;
	sf::Event event;
	sf::Clock clock;
public:
	Windows(int width, int height);
	virtual ~Windows();

	virtual void draw() = 0;
	virtual void run() = 0;
};

Windows::Windows(int width, int height) : width(width), height(height) {}

Windows::~Windows() {}
