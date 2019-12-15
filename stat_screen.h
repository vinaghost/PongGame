#pragma once
#include "screen.h"
class StatScreen : public Screen {
private:

	Font font;
	Text szTitle;

	Sprite spTable;
	Texture texTable;

	Text szName[10];
	Text szScore[10];

	Text szBack;

	vector<pair<string, int>> userScores;

	bool isTextClicked(Text text);
protected:
	void processEvents();
	void update();
	void render();
	void reset();
public:
	StatScreen(RenderWindow* window, Setting* seting);
	~StatScreen();
};
