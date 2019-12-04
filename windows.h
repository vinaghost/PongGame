#ifndef _WINDOWS_H

#define _WINDOWS_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Windows {
protected:
	int width, height;
	RenderWindow renderWindow;
	Event event;
	Clock clock;

public:
	Windows(int width, int height);
	virtual ~Windows();

	void run();
};

#endif