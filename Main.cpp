//#include "menu.h"
//#include "Utils.h"

//#include <SFML\Window.hpp>
//#include "SFML\Window\Event.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"

#include <iostream>
using namespace std;
using namespace sf;

int main() {
	/*Menu menuMain;
	Utils::fixConsoleWindow();

	menuMain.addItem("Bat dau");
	menuMain.addItem("Setting");
	menuMain.addItem("Thoat");

	menuMain.setCoordItem(30, 10);
	menuMain.show();
	menuMain.getChoice();*/

	/*sf::Window window;
	sf::Event event;
	while (window.pollEvent(event))
	{
		int dem = -1;
		int titleCoord_First = menuMain.gettitleCoord_First();
		int titleCoord_Second = menuMain.gettitleCoord_Second();
		int itemName_Size = menuMain.getitem_size();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				int x = event.mouseButton.x;
				int y = event.mouseButton.y;
				for (int item = 0; item < itemName_Size; item++)
				{
					if (y == (titleCoord_Second + item * 2))
					{
						int itemName_stringsize = menuMain.getstring_size(item);
						if ((x >= titleCoord_First) && (x <= titleCoord_First + itemName_stringsize))
						{
							dem = item;
						}
					}
				}
			}
		}
		if ((dem >= 0) && (dem <= itemName_Size))
		{
			cout << "done";
			break;
		}
	}*/

	Text text;
	text.setString("hello");
	sf::Font font;
	font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");



	text.setFont(font);

	text.setFillColor(sf::Color(0, 255, 255, 255 * 0.3));
	RenderWindow renderwindow;
	renderwindow.create(VideoMode(800, 600), "hello");
	renderwindow.draw(text);
	return 0;
}