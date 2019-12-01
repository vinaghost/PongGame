#include "Menu.h"



#include "Utils.h"

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Event.hpp"

#include <iostream>

Menu::Menu(RenderWindow* window, float x, float y) : window(window), x(x), y(y) {};

Menu::~Menu() {};

void Menu::setX(float x)
{
	this->x = x;
}

void Menu::setY(float y)
{
	this->y = y;
}

float Menu::getX()
{
	return this->x;
}

float Menu::getY()
{
	return this->y;
}

void Menu::setButtons(string a)
{
	S.push_back(a);
}

void Menu::setMenu(int distance)
{
	Text text;
	font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");
	text.setFont(font);
	text.setPosition(x, y);
	//text.setCharacterSize(24); // in pixels, not points!                         
	//text.setColor(sf::Color::White);   // set the color  
	//text.setStyle(sf::Text::Bold); // set the text style

	//set positions of things
	for (int i = 0; i < S.size(); i++)
	{
		buttons.push_back(text);
		buttons[i].setPosition(text.getPosition().x, text.getPosition().y + i * distance);
		buttons[i].setString(S[i]);
	}

	//Since it's only 3 text its fine to just manually set each...
	//buttons[0].setString("Play Game");
	//buttons[1].setString("Options");
	//buttons[2].setString("Quit");
	
}

void Menu::draw()
{
	//draw text
	for (auto x : buttons)
		window->draw(x);
	
}

bool Menu::isTextClicked(Text text)
{
	sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

	//If mouse position is in the rectangle do whatever
	if (rect.contains(Mouse::getPosition(*window)))
		return true;


	//Otherwise, don't do anything
	return false;
}

