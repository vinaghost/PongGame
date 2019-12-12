#include "caption.h"

Caption::Caption()
{
	font.loadFromFile("Resources/Montserrat-Black.ttf");
	text.setFont(font);
}

Caption::~Caption() {}

void Caption::setString(string name)
{
	text.setString(name);
}

void Caption::draw()
{
	window->draw(this->text);
}

void Caption::setPosition(float x, float y)
{
	text.setPosition(x, y);
}

void Caption::setRenderWindow(RenderWindow* window)
{
	this->window = window;
}

void Caption::setColor(string color)
{
	if (color == "Black")
	{
		this->text.setFillColor(Color::Black);
	}
	else if (color == "White")
	{
		this->text.setFillColor(Color::White);
	}
	else if (color == "Red")
	{
		this->text.setFillColor(Color::Red);
	}
	else if (color == "Green")
	{
		this->text.setFillColor(Color::Green);
	}
	else if (color == "Blue")
	{
		this->text.setFillColor(Color::Blue);
	}
	else if (color == "Yellow")
	{
		this->text.setFillColor(Color::Yellow);
	}
	else if (color == "Magenta")
	{
		this->text.setFillColor(Color::Magenta);
	}
	else if (color == "Cyan")
	{
		this->text.setFillColor(Color::Cyan);
	}
	else if (color == "Transparent")
	{
		this->text.setFillColor(Color::Transparent);
	}
}