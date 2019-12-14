#pragma once
#include "menu.h"
#include <string>
#include <map>

using std::string;

class Setting {
private:

	RenderWindow* window;
	Event event;
	float x, y;

	string szName;

	std::map<string, int> score;

	Font font;

	Text szInput;
	Text szScore;
	Text szLoad, szBack;

	bool clicked;

	int state;

public:
	Setting(RenderWindow* window, float x, float y);
	virtual ~Setting();

	void processEvents();

	void draw();

	String getName();
	int getScore();

	void checkName();
	int load();
	int save();

	bool isTextClicked(Text text);

	int getState();
};
