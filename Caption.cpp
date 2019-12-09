#include "Caption.h"



Caption::Caption()
{
	font.loadFromFile("Resources/Montserrat-Black.ttf");
	x = 0; 
	y = 0;
}


Caption::~Caption() {}

void Caption::setString(string name)
{
	this->name_text = name;
}

void Caption::draw()
{
	window->draw(this->text);
}

void Caption::setCoord(float x, float y)
{
	this->x = x;
	this->y = y;
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

void Caption::update()
{
	text.setFont(font);
	text.setPosition(x, y);
	text.setString(name_text);
	draw();
}