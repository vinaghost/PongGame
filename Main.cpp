#include "charts.h"

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
	charts achive(&window, 350, 40);
	achive.loadfromFile();
	achive.sort();
	
	while (window.isOpen())
	{
		window.clear();
		
		achive.drawCharts(30);
		achive.processEvents();
		window.display();
	}
	return EXIT_SUCCESS;
}