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
	
	Menu menu;
	menu.setScreenX(screenX);
	menu.setScreenY(screenY);
	menu.setX(100);
	menu.setY(100);
	menu.setButtons("Play Game");
	menu.setButtons("Settings");
	menu.setButtons("Exit");
	menu.setRenderWindow();
	menu.setMenu();
	menu.draw();
	menu.windowDisplay();
	
	menu.handleInput();
	
	
	return EXIT_SUCCESS;
}