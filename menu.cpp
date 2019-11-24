#include "Menu.h"

#include "Utils.h"

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Event.hpp"

#include <iostream>



Menu::Menu(double x, double y)
{
	sf::Text text;
	font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");
	text.setFont(font);
	text.setPosition(x, y);
	//text.setCharacterSize(24); // in pixels, not points!                         
	//text.setColor(sf::Color::White);   // set the color  
	//text.setStyle(sf::Text::Bold); // set the text style

	//set positions of things
	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		buttons.push_back(text);
		buttons[i].setPosition(text.getPosition().x, text.getPosition().y + i * 100);
	}

	//Since it's only 3 text its fine to just manually set each...
	buttons[0].setString("Play Game");
	buttons[1].setString("Options");
	buttons[2].setString("Quit");
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	//draw text
	for (auto x : buttons)
		window.draw(x);
}

bool Menu::isTextClicked(sf::Text text, sf::RenderWindow &window)
{
	sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

	//If mouse position is in the rectangle do whatever
	if (rect.contains(sf::Mouse::getPosition(window)))
		return true;


	//Otherwise, don't do anything
	return false;
}

void Menu::handleInput(sf::RenderWindow &window)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
		case sf::Event::Closed:
			window.close();
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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (isTextClicked(buttons[0], window))
			{
				Text text;
				text.setString("hello");
				sf::Font font;
				font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");
				window.create(VideoMode(800, 600), "hello");
				window.draw(text);
				window.display();
			}

			else if (isTextClicked(buttons[2], window))
				window.close();


		}
	}
}