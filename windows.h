#ifndef _WINDOWS_H

#define _WINDOWS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "screen.h"
#include "setting.h"
using namespace sf;

class Windows {
protected:
	RenderWindow renderWindow;
	std::vector<Screen*> screens;
	Setting* setting;
	int screen;
public:
	Windows();
	virtual ~Windows();

	void run();
};

#endif