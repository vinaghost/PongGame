#include "stat_screen.h"
#include "globals.h"
StatScreen::StatScreen(RenderWindow* window, Setting* setting) : Screen(window, setting) {
	font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");

	texTable.loadFromFile("Resources/stat.png");
	spTable.setTexture(texTable, true);
	spTable.setPosition(150, 100);

	szTitle.setFont(font);
	szTitle.setString("TOP 10");
	szTitle.setPosition(globals::SCREEN_WIDTH / 2 - 10, 50);

	for (int i = 0; i < 10; i++) {
		szName[i].setFont(font);
		szScore[i].setFont(font);

		szName[i].setString("#");
		szScore[i].setString("#");

		szName[i].setPosition(220, 135.0f + 33 * i);
		szScore[i].setPosition(670, 135.0f + 33 * i);
	}

	szBack.setPosition(600, 550);
	szBack.setFont(font);
	szBack.setString("Back");
}

StatScreen::~StatScreen() {}

void StatScreen::reset() {
	szBack.setFillColor(Color::White);
}
void StatScreen::processEvents() {
	while (window->pollEvent(event)) {
		switch (event.type) {
		case Event::Closed:
			window->close();
			loop = false;
			nextScreen = EXIT;
			break;
		case Event::MouseButtonPressed:
			if (event.mouseButton.button == Mouse::Left) {
				if (isTextClicked(szBack)) {
					loop = false;
					nextScreen = MAIN_MENU;
					szBack.setFillColor(Color::Green);
				}
			}
			break;
		}
	}
}
void StatScreen::update() {
	userScores = setting->getSorted();

	int count = 0;

	char str[33];
	for (auto &i : userScores) {
		szName[count].setString(i.first);

		sprintf_s(str, "%d", i.second);
		szScore[count].setString(str);

		count++;
		if (count >= 10) break;
	}
}
void StatScreen::render() {
	window->draw(spTable);
	window->draw(szTitle);

	for (auto &i : szName) {
		window->draw(i);
	}
	for (auto &i : szScore) {
		window->draw(i);
	}
	window->draw(szBack);
}

bool StatScreen::isTextClicked(Text text)
{
	sf::IntRect rect((int)text.getPosition().x, (int)text.getPosition().y, (int)text.getGlobalBounds().width, (int)text.getGlobalBounds().height);

	//If mouse position is in the rectangle do whatever
	if (rect.contains(Mouse::getPosition(*window)))
		return true;

	//Otherwise, don't do anything
	return false;
}