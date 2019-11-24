#include "menu.h"
#include "Utils.h"
//#include "Utils.h"

//#include <SFML\Window.hpp>
//#include "SFML\Window\Event.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"

#include <iostream>
using namespace std;
using namespace sf;


int main() {
	const int screenX = 800;
	const int screenY = 600;
	sf::RenderWindow window;
	Menu menu(screenX, screenY, window);
	menu.setMenu(100, 100);
	window.clear(sf::Color::Black);
	menu.draw(window);
	window.display();
	while (window.isOpen())
	{
		menu.handleInput(window);
	}
	
	return EXIT_SUCCESS;
}