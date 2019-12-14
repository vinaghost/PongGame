//include Thư viện
#include "globals.h"
#include "board.h"
#include "ball.h"
#include "paddle.h"
#include "itemManager.h"

//include Thư viện

int main() {
	//Code test
	std::vector<Entity*> others;
	RenderWindow window(VideoMode(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT), "My window", Style::Default ^ Style::Resize);
	const int width = 500;
	const int height = 400;
	Board b(&window);
	//window.setKeyRepeatEnabled(false);
	b.setColor(255, 124, 0);
	b.setBackgroundColor(0, 0, 255);

	sf::Event event;
	sf::Clock clock;

	Int64 timeInterval;
	Ball *ball = new Ball(&window, &b, 20);
	ball->setBackgroundColor(0, 255, 0);

	ItemManager things(&window, &b);

	//Paddle *p1 = new Paddle(&window, &b, winners::LEFT);
	//p1->setBackgroundColor(255, 0, 0);
	//others.push_back(p1);
	//Paddle *p2 = new Paddle(&window, &b, winners::RIGHT);

	//p2->setBackgroundColor(255, 0, 0);
	//others.push_back(p2);

	Font dFont;
	dFont.loadFromFile("Resources/Montserrat-Black.ttf");

	Text WinnerName;

	WinnerName.setFont(dFont);
	WinnerName.setCharacterSize(200 / 6);
	WinnerName.setFillColor(Color::White);

	sf::FloatRect bound1(WinnerName.getLocalBounds());
	WinnerName.setPosition(width / 2 - (bound1.left + bound1.width / 2), height / 2 - (bound1.top + bound1.height / 2));
	WinnerName.setPosition(100, 100);

	WinnerName.setString(L"Á à a");

	std::vector<Entity*> objects;
	std::vector<Item*> things1;
	things.createItem(&b);

	while (window.isOpen()) {
		window.clear();
		while (window.pollEvent(event)) {
			//Xử lý khi người dùng nhấn X để thoát
			if (event.type == Event::EventType::Closed)
				window.close();
			//Xử lý người dùng nhấn phím bất kỳ để chạy paddle
			if (event.type == Event::EventType::KeyPressed)
				if (ball->getIdle()) ball->randomDirection();
		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			//p1->moveUp();
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			//p1->moveDown();
		}
		if (!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S)) {
			//p1->stopMoving();
		}

		if (Keyboard::isKeyPressed(Keyboard::I)) {
			//p2->moveUp();
		}
		if (Keyboard::isKeyPressed(Keyboard::K)) {
			//p2->moveDown();
		}
		if (!Keyboard::isKeyPressed(Keyboard::I) && !Keyboard::isKeyPressed(Keyboard::K)) {
			//p2->stopMoving();
		}

		if (Keyboard::isKeyPressed(Keyboard::R)) {
			//p1->reset();
			//p2->reset();
			ball->reset();
		}

		//Tính khoảng thời gian render giữa 2 frame
		timeInterval = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		if (ball->getWinner() != winner::NONE) {
			window.draw(WinnerName);
		}
		else {
			objects.clear();
			things1.clear();
			things1 = things.spawnedItem();
			for (int i = 0; i < others.size(); i++)
			{
				objects.push_back(others[i]);
			}
			for (int i = 0; i < things1.size(); i++)
			{
				objects.push_back(things1[i]);
			}

			//p1->update(timeInterval);
			//p2->update(timeInterval);
			ball->handleCollisions(objects);
			ball->update(timeInterval);
			things.processEvents();

			b.draw();
			ball->draw();
			//p1->draw();
			//p2->draw();
			things.draw();
		}
		window.display();
	}

	delete ball;
	//delete p1;
	//delete p2;

	//Code test
	return 0;
}