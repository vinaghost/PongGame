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
	float x, y;
	Text text;
	string name_text;
public:
	Caption();
	~Caption();
	void setString(string);
	void draw();
	void update();
	void setCoord(float x, float y);
	void setRenderWindow(RenderWindow* window);
	void setColor(string color);
};

