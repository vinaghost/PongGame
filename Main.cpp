//include Thư viện
#include "board.h"
//include Thư viện

int main() {
	//Code test
	RenderWindow window(VideoMode(800, 600), "My window", Style::Default ^ Style::Resize);
	Board b(200, 100, &window);
	b.setX(30);
	b.setY(30);
	b.draw();
	sf::Event event;
	window.display();
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	//Code test
	return 0;
}