//include Thư viện
#include "board.h"
#include "ball.h"
#include "paddle.h"
//include Thư viện

int main() {
	//Code test

	RenderWindow window(VideoMode(800, 600), "My window", Style::Default ^ Style::Resize);
	Board b(&window, 50, 50, 500, 400);
	//window.setKeyRepeatEnabled(false);
	b.setColor(255, 124, 0);
	b.setBackgroundColor(0, 0, 255);

	sf::Event event;
	sf::Clock clock;

	Int64 timeInterval;
	Ball ball(&window, &b, 500, 200, 20);
	ball.setBackgroundColor(0, 255, 0);

	Paddle p1(&window, &b, 50, 50 + 400 / 2, 10, 100);
	p1.setBackgroundColor(255, 0, 0);

	Paddle p2(&window, &b, 550 - 10, 50 + 400 / 2, 10, 100);
	p2.setBackgroundColor(255, 0, 0);

	while (window.isOpen()) {
		window.clear();
		while (window.pollEvent(event)) {
			//Xử lý khi người dùng nhấn X để thoát
			if (event.type == Event::EventType::Closed)
				window.close();
			//Xử lý người dùng nhấn phím bất kỳ để chạy paddle
			if (event.type == Event::EventType::KeyPressed)
				if (ball.getIdle()) ball.randomDirection();
			if (Keyboard::isKeyPressed(Keyboard::W)) {
				p1.moveUp();
			}
			if (Keyboard::isKeyPressed(Keyboard::S)) {
				p1.moveDown();
			}
			if (!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S)) {
				p1.stopMoving();
			}

			if (Keyboard::isKeyPressed(Keyboard::I)) {
				p2.moveUp();
			}
			if (Keyboard::isKeyPressed(Keyboard::K)) {
				p2.moveDown();
			}
			if (!Keyboard::isKeyPressed(Keyboard::I) && !Keyboard::isKeyPressed(Keyboard::K)) {
				p2.stopMoving();
			}

			if (Keyboard::isKeyPressed(Keyboard::R)) {
				p1.reset();
				p2.reset();
				ball.reset();
			}
		}

		//Tính khoảng thời gian render giữa 2 frame
		timeInterval = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		ball.update(timeInterval);
		p1.update(timeInterval);
		p2.update(timeInterval);

		b.draw();
		ball.draw();
		p1.draw();
		p2.draw();

		window.display();
	}

	//Code test
	return 0;
}