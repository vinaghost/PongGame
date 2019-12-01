﻿//#include "MenuMain.h"
#include "MenuMain.h"
#include "MenuSetting.h"
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
	MenuMain main(&window, 100, 100);
	main.show();
	while (window.isOpen())
	{
		main.update();
	}
	return EXIT_SUCCESS;
}