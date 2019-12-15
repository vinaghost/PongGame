#include "setting.h"
#include "globals.h"
#include <fstream>
#include <sstream>
#include <utility>

using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::getline;
using std::make_pair;

Setting::Setting(RenderWindow* window, float x, float y) : state(0), window(window), x(x), y(y), loaded(false), clicked(false) {
	font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");

	szInput.setPosition(x, y);
	szInput.setString("Name: " + szName);
	szInput.setFont(font);

	szScore.setPosition(x, y + 50);
	szScore.setFont(font);
	szScore.setString("Score: <Not load yet>");

	szLoad.setPosition(x, y + 300);
	szLoad.setFont(font);
	szLoad.setString("Load");

	szReset.setPosition(x + 300, y + 300);
	szReset.setFont(font);
	szReset.setString("Reset");

	szBack.setPosition(x + 600, y + 300);
	szBack.setFont(font);
	szBack.setString("Back");
}

Setting::~Setting() {
}

void Setting::draw() {
	window->draw(szInput);
	window->draw(szScore);
	window->draw(szLoad);
	window->draw(szReset);
	window->draw(szBack);
}
void Setting::reset() {
	szInput.setFillColor(Color::White);
	szBack.setFillColor(Color::White);
	szReset.setFillColor(Color::White);
	szLoad.setFillColor(Color::White);
}
void Setting::processEvents() {
	state = 0;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window->close();
			state = 1;
			break;
		case Event::MouseButtonPressed:
			if (event.mouseButton.button == Mouse::Left) {
				if (isTextClicked(szInput)) {
					clicked = true;
					szInput.setFillColor(Color::Green);
				}
				else {
					clicked = false;
					szInput.setFillColor(Color::White);
				}

				if (isTextClicked(szBack)) {
					state = 2;
					szBack.setFillColor(Color::Green);
				}
				else {
					szBack.setFillColor(Color::White);
				}

				if (isTextClicked(szLoad)) {
					checkName();
					szLoad.setFillColor(Color::Green);
				}
				else {
					szLoad.setFillColor(Color::White);
				}
				if (isTextClicked(szReset)) {
					if (loaded)
						score[szName] = 0;
					szReset.setFillColor(Color::Green);
				}
				else {
					szReset.setFillColor(Color::White);
				}
			}
			break;
		case Event::TextEntered:

			if (event.text.unicode < 128)
			{
				if (clicked) {
					if (event.text.unicode == '\b') {
						if (szName.length() > 0)
							szName.erase(szName.length() - 1);
					}
					else {
						szName += event.text.unicode;
					}
					szInput.setString("Name: " + szName);
					loaded = false;
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

int Setting::getScore() {
	return score[szName];
}
void Setting::setScore(int score) {
	this->score[szName] = score;
}
int Setting::save() {
	ofstream f(filename::scoreFile);

	if (f.good()) {
		for (const auto& i : score) {
			//if (i.second != 0)
			f << i.first << "," << i.second << "\n";
		}
		f.close();
	}
	return score.size();
}

int Setting::load() {
	ifstream f(filename::scoreFile);

	if (f.good()) {
		stringstream ss;
		string line_info;

		string name;
		int score;
		while (getline(f, line_info)) {
			ss.clear();
			ss << line_info;

			getline(ss, name, ',');
			ss >> score;

			this->score.insert(make_pair(name, score));
		}
	}
	return score.size();
}

void Setting::checkName() {
	if (szName.empty()) return;

	auto it = score.find(szName);
	if (it == score.end()) {
		this->score.insert(make_pair(szName, 0));
	}

	int tmp = score[szName];

	char str[33];
	sprintf_s(str, "Score: %d", tmp);

	szScore.setString(str);

	loaded = true;
}

int Setting::getState() {
	return this->state;
}