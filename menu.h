#pragma once

#include "SFML/Graphics.hpp"

#include <vector>
using namespace std;
using namespace sf;

#define NUM_BUTTONS 3

class Menu
{
private:
	vector<Text> buttons;
	Font font;
	double x, y;
	RenderWindow window;
public:
	Menu(double x, double y);
	~Menu();

	void draw(RenderWindow &window);
	bool isTextClicked(Text text, RenderWindow &window);
	void handleInput(sf::RenderWindow &window);
	


};