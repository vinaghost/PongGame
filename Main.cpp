#include "menusetting.h"

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
	RenderWindow window(VideoMode(800, 600), "My window", Style::Default ^ Style::Resize);
	MenuSetting main(&window, 100, 200);

	while (window.isOpen())
	{
		window.clear();

		main.processEvents();

		main.draw();
		window.display();
	}
	return EXIT_SUCCESS;
}