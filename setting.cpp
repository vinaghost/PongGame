#include "setting.h"

Setting::Setting(RenderWindow* window, float x, float y) {
	font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");

	szInput.setPosition(x, y);
	szInput.setString("Name: " + szName);
	szInput.setFont(font);
}

Setting::~Setting() {
}

void Setting::draw() {
	window->draw(szInput);
}

void Setting::processEvents() {
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window->close();
			break;
		case Event::MouseButtonPressed:
			if (event.mouseButton.button == Mouse::Left) {
				if (isTextClicked(szInput)) {
					clicked = true;
				}
				else {
					clicked = false;
				}
			}
			break;
		case Event::TextEntered:

			if (event.text.unicode < 128)
			{
				if (clicked) {
					if (event.text.unicode == '\b') {
						szName.erase(szName.getSize() - 1);
					}
					else {
						szName += event.text.unicode;
					}
					szInput.setString("Name: " + szName);
				}
			}
			break;
		}
	}
}

bool Setting::isTextClicked(Text text)
{
	sf::IntRect rect((int)text.getPosition().x, (int)text.getPosition().y, (int)text.getGlobalBounds().width, (int)text.getGlobalBounds().height);

	//If mouse position is in the rectangle do whatever
	if (rect.contains(Mouse::getPosition(*window)))
		return true;

	//Otherwise, don't do anything
	return false;
}

String Setting::getName() {
	return szName;
}