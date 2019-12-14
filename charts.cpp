#define _CRT_SECURE_NO_WARNINGS
#include "charts.h"

#include <sstream>
#include <fstream>

#include <iostream>
using namespace std;


charts::charts(RenderWindow* window, float x, float y): Menu(window, x, y)
{
}


charts::~charts()
{
}

int charts::getState()
{
	return this->state;
}

void charts::loadfromFile()
{
	fstream f;
	f.open("userinfo.dat", ios::in);
	string line;
	getline(f, line);
	pair<string, int> user;
	while (!f.eof())
	{
		getline(f, line);
		stringstream str_strm;
		str_strm << line;
		vector<string> words;
		while (!str_strm.eof())
		{
			string tmp;
			str_strm >> tmp;
			words.push_back(tmp);
		}
		for (int dem = 0; dem < words.size(); dem++)
		{
			if (dem == 0)
			{
				user.first = words[dem];
			}
			else if (dem == 1)
			{
				user.second = atoi(words[dem].c_str());
			}
		}
		users.push_back(user);
	}
	f.close();
	for (int i = 0; i < users.size(); i++)
	{
		cout << users[i].first << endl;
		cout << users[i].second << endl;
	}
}

void charts::change_place(pair<string, int>& user1, pair<string, int>& user2)
{
	pair<string, int> a;
	a.first = user1.first;
	a.second = user1.second;
	user1.first = user2.first;
	user1.second = user2.second;
	user2.first = a.first;
	user2.second = a.second;
}

void charts::sort()
{
	for (int i = 0; i < users.size(); i++)
	{
		for (int j = 0; j < users.size(); j++)
		{
			if (users[i].second < users[j].second)
			{
				change_place(users[i], users[j]);
			}
		}
	}
}
void charts::drawCharts(int distance)
{
	Text text;
	text.setFont(font);
	text.setString("Chart");
	text.setPosition(350, 10);
	window->draw(text);
	if (users.size() < 10)
	{
		for (int i = 0; i < users.size(); i++)
		{
			text.setString(users[i].first);
			text.setPosition(x, y + i * distance);
			window->draw(text);
			string result;
			ostringstream convert;
			convert << users[i].second;
			result = convert.str();
			text.setString(result);
			text.setPosition(x + 50, y + i * distance);
			window->draw(text);
		}
		for (int i = users.size(); i < 10; i++)
		{
			text.setString("<ten>");
			text.setPosition(x, y + i * distance);
			window->draw(text);
			text.setString("<diem>");
			text.setPosition(x + 90, y + i * distance);
			window->draw(text);
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			text.setString(users[i].first);
			text.setPosition(x, y + i * distance);
			window->draw(text);
			string result;
			ostringstream convert;
			convert << users[i].second;
			result = convert.str();
			text.setString(result);
			text.setPosition(x + 50, y + i * distance);
			window->draw(text);
		}
	}
	text.setPosition(350, 550);	
	text.setString("Back");
	buttons.push_back(text);
	buttons[0].setPosition(text.getPosition().x, text.getPosition().y);
	this->draw();

}
void charts::processEvents()
{
	this->state = 0;
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
	
	    if (isTextClicked(buttons[0])) {
			this->state = 1;
				
		
		}
	}
	
}