#include "MenuMain.h"

#include "Utils.h"

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Event.hpp"

#include <iostream>



MenuMain::MenuMain(RenderWindow* window, float x, float y) : window(window), x(x), y(y) {};

void MenuMain::setX(float x)
{
	this->x = x;
}

void MenuMain::setY(float y)
{
	this->y = y;
}

float MenuMain::getX()
{
	return this->x;
}

float MenuMain::getY()
{
	return this->y;
}

void MenuMain::setButtons(string a)
{
	S.push_back(a);
}

void MenuMain::setMenu(int distance)
{
	Text text;
	font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");
	text.setFont(font);
	text.setPosition(x, y);

	//set positions of things
	for (int i = 0; i < S.size(); i++)
	{
		buttons.push_back(text);
		buttons[i].setPosition(text.getPosition().x, text.getPosition().y + i * distance);
		buttons[i].setString(S[i]);
	}

}

void MenuMain::draw()
{
	//draw text
	for (auto x : buttons)
		window->draw(x);
}

bool MenuMain::isTextClicked(Text text)
{
	sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

	//If mouse position is in the rectangle do whatever
	if (rect.contains(Mouse::getPosition(*window)))
		return true;


	//Otherwise, don't do anything
	return false;
}


void MenuMain::show()
{
	this->setButtons("Play Game");
	this->setButtons("Options");
	this->setButtons("Exit");
	this->setMenu(100);
	this->draw();
	window->display();
}

void MenuMain::update()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
		case Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				setMenu(100);
				draw();
				window->display();
			}
			//else if (event.key.code == sf::Keyboard::Return)
				//loadgame();
			break;

			//check if text is hovered over
		/*case sf::Event::MouseMoved:
			if (isTextClicked(buttons[0],window))
				buttons[0].setColor(sf::Color::Red);
			else
				buttons[0].setColor(sf::Color::White);
			if (isTextClicked(buttons[1], window))
				buttons[1].setColor(sf::Color::Red);
			else
				buttons[1].setColor(sf::Color::White);
			if (isTextClicked(buttons[2], window))
				buttons[2].setColor(sf::Color::Red);
			else
				buttons[2].setColor(sf::Color::White);
			break;
		}*/
		}
		//check if text is clicked.
		if (Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (isTextClicked(buttons[0]))
			{
				this->choice = 0;
				font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");
				Text text;
				text.setFont(font);
				text.setString("hello");
				window->draw(text);
				window->display();
			}

			else if (isTextClicked(buttons[1]))
			{
				this->choice = 1;
			}

			else if (isTextClicked(buttons[2]))
			{
                this->choice = 2;
			}
		}
	}
		
}

int MenuMain::getChoice() {
	return this->choice;
}