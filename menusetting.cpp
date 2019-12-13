#include "menusetting.h"
#include <iostream>
MenuSetting::MenuSetting(RenderWindow* window, float x, float y) : Menu(window, x, y), P1(false), P2(false) {
	ttNext.loadFromFile("Resources/next.png");
	ttBack.loadFromFile("Resources/back.png");

	addButtons("Mode : ");
	addButtons("Length's Paddle : ");
	initMenu(50);
}

MenuSetting::~MenuSetting() {
}

void MenuSetting::initMenu(int distance)
{
	szNameP1 = "Player 1: ";
	szNameP2 = "Player 2: ";

	szInputP1.setPosition(x, y - 100);
	szInputP1.setString(szNameP1);
	szInputP1.setFont(font);

	szInputP2.setPosition(x + 300, y - 100);
	szInputP2.setString(szNameP2);
	szInputP2.setFont(font);

	Text text;
	text.setFont(font);
	text.setPosition(x + 90, y);

	Sprite spNext, spBack;

	spBack.setTexture(ttBack, true);
	spBack.setPosition(x, y);

	spNext.setTexture(ttNext, true);
	spNext.setPosition(x + 45, y);

	for (size_t i = 0; i < nameItem.size(); i++) {
		buttons.push_back(text);
		buttons[i].setPosition(text.getPosition().x, text.getPosition().y + i * distance);
		buttons[i].setString(nameItem[i]);

		setting.push_back(0);

		settingButtons.push_back(text);
		settingButtons[i].setPosition(text.getPosition().x + 350, text.getPosition().y + i * distance);
		settingButtons[i].setString(szSetting[i][setting[i]]);

		arrowButtons.push_back(std::make_pair(spBack, spNext));
		arrowButtons[i].first.setPosition(spBack.getPosition().x, spBack.getPosition().y + i * distance);
		arrowButtons[i].second.setPosition(spNext.getPosition().x, spNext.getPosition().y + i * distance);
	}
}

void MenuSetting::draw() {
	//draw text
	for (auto x : buttons) {
		window->draw(x);
	}

	for (auto x : arrowButtons) {
		window->draw(x.first);
		window->draw(x.second);
	}
	for (auto x : settingButtons) {
		window->draw(x);
	}

	window->draw(szInputP1);
	window->draw(szInputP2);
}

void MenuSetting::processEvents() {
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window->close();
			break;
		case Event::MouseButtonPressed:
			if (event.mouseButton.button == Mouse::Left)
			{
				for (size_t i = 0; i < arrowButtons.size(); i++) {
					if (isTextClicked(arrowButtons[i].first)) {
						if (setting[i] > 0)
							setting[i] --;

						settingButtons[i].setString(szSetting[i][setting[i]]);
						break;
					}
					if (isTextClicked(arrowButtons[i].second)) {
						if (setting[i] < 1 && i == 0 || setting[i] < 2 && i != 0)
							setting[i] ++;
						settingButtons[i].setString(szSetting[i][setting[i]]);
						break;
					}
				}
				if (Menu::isTextClicked(szInputP1)) {
					P1 = true;
					P2 = false;
				}
				else if (Menu::isTextClicked(szInputP2)) {
					P1 = false;
					P2 = true;
				}
				else {
					P1 = false;
					P2 = false;
				}
			}
			break;
		case Event::TextEntered:

			if (event.text.unicode < 128)
			{
				if (P1) {
					if (event.text.unicode == '\b') {
						szNameP1.erase(szNameP1.getSize() - 1);
					}
					else {
						szNameP1 += event.text.unicode;
					}
					szInputP1.setString(szNameP1);
				}
				else if (P2) {
					if (event.text.unicode == '\b') {
						szNameP2.erase(szNameP2.getSize() - 1);
					}
					else {
						szNameP2 += event.text.unicode;
					}
					szInputP2.setString(szNameP2);
				}
			}
			break;
		}
	}
}

bool MenuSetting::isTextClicked(Sprite sprite) {
	sf::IntRect rect((int)sprite.getPosition().x, (int)sprite.getPosition().y, (int)sprite.getGlobalBounds().width, (int)sprite.getGlobalBounds().height);

	//If mouse position is in the rectangle do whatever
	if (rect.contains(Mouse::getPosition(*window)))
		return true;

	//Otherwise, don't do anything
	return false;
}