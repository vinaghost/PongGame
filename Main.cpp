//include Thư viện
#include "board.h"
#include "ball.h"
//include Thư viện

int main() {
	//Code test

	RenderWindow window(VideoMode(800, 600), "My window", Style::Default ^ Style::Resize);
	Board b(200, 100, &window);
	b.setX(30);
	b.setY(30);
	b.setColor(255, 124, 0);
	b.setBackgroundColor(0, 0, 0);

	sf::Event event;
	sf::Clock clock;

	Int64 timeInterval;
	Ball ball(&window, &b);

	ball.setup(40, 40, 20);
	ball.setBackgroundColor(0, 255, 0);

	while (window.isOpen())
	{
		window.clear();
		while (window.pollEvent(event)) {
			//Xử lý khi người dùng nhấn X để thoát
			if (event.type == Event::EventType::Closed)
				window.close();
			//Xử lý người dùng nhấn phím bất kỳ để chạy paddle
			if (event.type == Event::EventType::KeyPressed)
				if (ball.getIdle()) ball.randomDirection();
		}

		//Tính khoảng thời gian render giữa 2 frame
		timeInterval = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		ball.update(timeInterval);

		b.draw();
		ball.draw();

		window.display();
	}

	//Code test
	return 0;
}