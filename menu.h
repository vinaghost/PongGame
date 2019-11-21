#pragma once

#include "SFML/Graphics.hpp"

#include <vector>
using namespace std;

#define NUM_BUTTONS 3

class Menu
{
public:
	Menu(double x, double y);
	~Menu();

	void draw(sf::RenderWindow &window);
	bool isTextClicked(sf::Text text, sf::RenderWindow &window);
	void handleInput(sf::RenderWindow &window);
	

private:
	vector<sf::Text> buttons;
	sf::Font font;
};