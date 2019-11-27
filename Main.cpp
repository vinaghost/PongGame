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
	RenderWindow window(VideoMode(800, 600), "My window", Style::Default ^ Style::Resize);
	Menu menu(&window, 100, 100);
	menu.setButtons("Play Game");
	menu.setButtons("Options");
	menu.setButtons("Exit");
	menu.setMenu();
	menu.draw();
	menu.windowDisplay();
	menu.handleInput();
	
	return EXIT_SUCCESS;
}