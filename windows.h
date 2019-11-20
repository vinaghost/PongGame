#ifndef _WINDOWS_H

#define _WINDOWS_H

#include <SFML/Graphics.hpp>

using namespace sf;
#define FPS 60.0

double const mSPF = 1000000.0 / FPS;

class Windows {
protected:
	int width, height;
	RenderWindow renderWindow;
	Event event;
	Clock clock;
public:
	Windows(int width, int height);
	virtual ~Windows();

	virtual void draw() = 0;
	virtual void run() = 0;
};


#endif