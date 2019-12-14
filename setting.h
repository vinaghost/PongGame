#pragma once
#include "menu.h"
#include <string>

class Setting {
private:

	RenderWindow* window;
	Event event;
	float x, y;

	String szName;
	Text szInput;
	Font font;

	bool clicked;

public:
	Setting(RenderWindow* window, float x, float y);
	virtual ~Setting();

	void processEvents();

	void draw();

	String getName();

	bool isTextClicked(Text text);
};
