#pragma once
#include "menu.h"
#include <utility>
#include <string>

using std::pair;

class MenuSetting : public Menu {
private:
	Texture ttNext, ttBack;

	vector<pair<Sprite, Sprite>> arrowButtons;
	vector<int> setting;
	vector<Text> settingButtons;

	String szNameP1;
	String szNameP2;

	Text szInputP1;
	Text szInputP2;

	bool P1, P2;

	char szSetting[2][3][11] = {
		{"PVP", "PVE", "" },
		{"Short",  "Medium", "Long"}
	};

public:
	MenuSetting(RenderWindow* window, float x, float y);
	virtual ~MenuSetting();

	void initMenu(int distance);

	void processEvents();

	void draw();

	int getChoice() = delete;

	bool isTextClicked(Sprite sprite);
};
