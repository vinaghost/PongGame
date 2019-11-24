#pragma once

#include "SFML/Graphics.hpp"

#include <vector>
using namespace std;

#define NUM_BUTTONS 3

class Menu
{
private:
	vector<sf::Text> buttons;
	sf::Font font;
public:
	Menu(double x, double y, sf::RenderWindow &window);
	~Menu();

	void setMenu(double x, double y);
	void draw(sf::RenderWindow &window);
	bool isTextClicked(sf::Text text, sf::RenderWindow &window);
	void handleInput(sf::RenderWindow &window);
	


};