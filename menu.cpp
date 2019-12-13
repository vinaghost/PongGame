#include "Menu.h"

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Event.hpp"

#include <iostream>

Menu::Menu(RenderWindow* window, float x, float y) : window(window), x(x), y(y), choice(-1) {
	font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");
}

Menu::~Menu() {}

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

void Menu::addButtons(string a)
{
	nameItem.push_back(a);
}

void Menu::initMenu(int distance)
{
	Text text;
	text.setFont(font);
	text.setPosition(x, y);

	for (size_t i = 0; i < nameItem.size(); i++)
	{
		buttons.push_back(text);
		buttons[i].setPosition(text.getPosition().x, text.getPosition().y + i * distance);
		buttons[i].setString(nameItem[i]);
	}
}

void Menu::draw()
{
	//draw text
	for (auto x : buttons)
		window->draw(x);
}

bool Menu::isTextClicked(Text text)
{
	sf::IntRect rect((int)text.getPosition().x, (int)text.getPosition().y, (int)text.getGlobalBounds().width, (int)text.getGlobalBounds().height);

	//If mouse position is in the rectangle do whatever
	if (rect.contains(Mouse::getPosition(*window)))
		return true;

	//Otherwise, don't do anything
	return false;
}

void Menu::processEvents() {
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window->close();
			break;
		}
	}

	if (Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->choice = -1;
		for (size_t i = 0; i < nameItem.size(); i++) {
			if (isTextClicked(buttons[i])) {
				this->choice = i;
				break;
			}
		}
	}
}

int Menu::getChoice() {
	return this->choice;
}