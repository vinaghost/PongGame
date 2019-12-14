#pragma once
#include "menu.h"

#include <utility>
using std::pair;

class charts: public Menu
{
private: 
	vector<pair<string, int>> users;
	int state;
public: 
	charts(RenderWindow* window, float x, float y);
	~charts();
	int getState();
	void loadfromFile();
	void change_place(pair<string, int>& user1, pair<string, int>& user2);
	void sort();
	void drawCharts(int distance);
	void processEvents();
};

