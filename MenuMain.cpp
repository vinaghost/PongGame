#include "MenuMain.h"

#include "Utils.h"

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Event.hpp"

#include <iostream>



MenuMain::MenuMain(RenderWindow* window, float x, float y) : Menu(window,x,y) 
{
	this->setButtons("Play Game");
	this->setButtons("Options");
	this->setButtons("Exit");
};


void MenuMain::show()
{
	
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