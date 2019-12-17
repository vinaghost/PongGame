#pragma once
#include <SFML/Audio.hpp>

#include "menu.h"
#include <string>
#include <map>
#include <utility>

using std::string;
using std::pair;

class Setting {
private:

	Music music;

	RenderWindow* window;
	Event event;
	float x, y;

	string szName;

	std::map<string, int> score;

	Font font;

	Text szInput;
	Text szScore;
	Text szMusic;
	Text szLoad, szReset, szBack;

	bool clicked;
	bool loaded;

	int state;

public:
	Setting(RenderWindow* window, float x, float y);
	virtual ~Setting();

	void reset();

	void processEvents();

	void draw();

	String getName();

	void setScore(int score);
	int getScore();
	bool getLoaded();

	void checkName();
	vector<pair<string, int>> getSorted();
	int load();
	int save();

	bool isTextClicked(Text text);

	int getState();
};
