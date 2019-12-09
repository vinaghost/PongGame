//include Thư viện
#include "Caption.h"

//include Thư viện

int main() {
	//Code test
	RenderWindow window;
	window.create(sf::VideoMode(800, 600), "Sick Game");
	Caption test;
	test.setRenderWindow(&window);
	test.setCoord(100, 100);
	test.setString("Ok");
	test.setColor("While");
	test.update();
	window.display();
	Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			}
		}
	}

	//Code test
	return 0;
}