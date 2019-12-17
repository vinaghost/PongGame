#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

using namespace sf;
using std::string;
class Caption
{
protected:
	RenderWindow* window;
	Font font;

	Text text;
public:
	Caption();
	~Caption();
	void setString(string);
	void draw();
	void setPosition(float x, float y);
	void setRenderWindow(RenderWindow* window);
	void setColor(string color);
};
