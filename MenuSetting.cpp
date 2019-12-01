#include "MenuSetting.h"


MenuSetting::MenuSetting(RenderWindow* window, float x, float y): window(window), x(x), y(y), Menu(window, x, y)
{
	string a, b;
	for (int item = 0; item < SAVE; item++)
	{
		b = constNameSettings[item][0];
		if (item == 0)
		{
			a = a = szSetting[item][0];
			itemSetting.push_back(0);
			this->setButtons(b + a);
		}
		else
		{
			a = a = szSetting[item][1];
			itemSetting.push_back(1);
			this->setButtons(b + a);
		}
	}
	this->setButtons("Luu");
}


MenuSetting::~MenuSetting()
{
}

int MenuSetting::getMode() { return itemSetting[MODE]; }

int MenuSetting::getLengthStick() { return itemSetting[LENGTH_STICK]; }

int MenuSetting::getSizeBoard() { return itemSetting[SIZE_BOARD]; }

int MenuSetting::getSpeedBall() { return itemSetting[SPEED_BALL]; }

int MenuSetting::getSpeedStick() { return itemSetting[SPEED_STICK]; }


void MenuSetting::resetMenuSettings(int item)
{
	S.clear();
	string a, b;
	for (int i = 0; i < SAVE; i++)
	{
		if (i == item)
		{
			a = szSetting[item][this->itemSetting[item]];
			b = constNameSettings[item][0];
			this->setButtons(b + a);
		}
		else
		{
			a = szSetting[i][this->itemSetting[i]];
			b = constNameSettings[i][0];
			this->setButtons(b + a);
		}
	}
	this->setButtons("Luu");
}

void MenuSetting::show()
{
	Text text;
	font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");
	text.setFont(font);
	text.setString("Settings");
	window->draw(text);
	this->setMenu(50);
	this->draw();
	window->display();
}

void MenuSetting::changeItem(int item)
{
	itemSetting[item] = itemSetting[item] + 1;
	if ((item == MODE) && (itemSetting[item] > 1))
	{
		itemSetting[item] = 0;
	}
	else if ((item != MODE) && (itemSetting[item] > 2))
	{
		itemSetting[item] = 0;
	}
}

void MenuSetting::update()
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
				
			}
			break;
		}
		
		//check if text is clicked.
		if (Mouse::isButtonPressed(sf::Mouse::Left))
		{
			int item;
			if (isTextClicked(buttons[0]))
			{
				item = 0;
				changeItem(item);
				resetMenuSettings(item);
				window->clear();
				show();
			}

			else if (isTextClicked(buttons[1]))
			{
				item = 1;
				changeItem(item);
				resetMenuSettings(item);
				window->clear();
				show();
			}

			else if (isTextClicked(buttons[2]))
			{
				item = 2;
				changeItem(item);
				resetMenuSettings(item);
				window->clear();
				show();
			}
			else if (isTextClicked(buttons[3]))
			{
				item = 3;
				changeItem(item);
				resetMenuSettings(item);
				window->clear();
				show();
			}
			else if (isTextClicked(buttons[4]))
			{
				item = 4;
				changeItem(item);
				resetMenuSettings(item);
				window->clear();
				show();
			}
			else if (isTextClicked(buttons[5]))
			{
				
			}
		}
	}
}