﻿#include "Menu.h"

#include "Utils.h"

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Event.hpp"

#include <iostream>

Menu::Menu() {};

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

void Menu::setMenu()
{
	sf::Text text;
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
		buttons[i].setPosition(text.getPosition().x, text.getPosition().y + i * 100);
		buttons[i].setString(S[i]);
	}

	//Since it's only 3 text its fine to just manually set each...
	//buttons[0].setString("Play Game");
	//buttons[1].setString("Options");
	//buttons[2].setString("Quit");
}

void Menu::setScreenX(float screenX)
{
	this->screenX = screenX;
}

void Menu::setScreenY(float screenY)
{
	this->screenY = screenY;
}

float Menu::getScreenX()
{
	return this->screenX;
}

float Menu::getScreenY()
{
	return this->screenY;
}

void Menu::setRenderWindow()
{
	window.create(VideoMode(screenX, screenY), "Pong", sf::Style::Titlebar | sf::Style::Close);
}

void Menu::draw()
{
	//draw text
	for (auto x : buttons)
		window.draw(x);
}

bool Menu::isTextClicked(Text text)
{
	sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

	//If mouse position is in the rectangle do whatever
	if (rect.contains(Mouse::getPosition(window)))
		return true;


	//Otherwise, don't do anything
	return false;
}

void Menu::handleInput()
{
	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				/* Close the window */
			case Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
				
					setMenu();
					setRenderWindow();
					draw();
					windowDisplay();
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
					Font font;
					font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");
					Text text;
					text.setString("hello");
					
					window.create(VideoMode(800, 600), "hello");
					window.draw(text);
					window.display();
				}

				else if (isTextClicked(buttons[2]))
					window.close();


			}
		}
	}
}

void Menu::windowDisplay()
{
	window.display();
}