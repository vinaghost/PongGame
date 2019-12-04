#ifndef _WINDOWS_H

#define _WINDOWS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "screen.h"
using namespace sf;

class Windows {
protected:
	RenderWindow renderWindow;
	std::vector<Screen*> screens;
	int screen;
public:
	Windows();
	virtual ~Windows();

	void run();
};

#endif