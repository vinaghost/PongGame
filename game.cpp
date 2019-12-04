#include "game.h"
#include <vector>

using std::vector;

Game::Game(RenderWindow* window) : Screen(window), endGame(false) {
	srand((unsigned int)time(NULL));

	b = new Board(window);
	b->setColor(255, 124, 0);
	b->setBackgroundColor(0, 0, 255);

	ball = new Ball(window, b, 20);
	ball->setBackgroundColor(0, 255, 0);

	p1 = new Paddle(window, b, 50, 50 + 400 / 2, 10, 100);
	p1->setBackgroundColor(255, 0, 0);
	others.push_back(p1);

	p2 = new Paddle(window, b, 550 - 10, 50 + 400 / 2, 10, 100);
	p2->setBackgroundColor(255, 0, 0);
	others.push_back(p2);

	/*nPlayer = n;
	if (n == 1) nameP1 = "BOT";*/
}

Game::~Game() {
	delete ball;
	delete p1;
	delete p2;
}

void Game::processEvents() {
	while (window->pollEvent(event)) {
		//Xử lý khi người dùng nhấn X để thoát
		if (event.type == Event::EventType::Closed)
			window->close();
		//Xử lý người dùng nhấn phím bất kỳ để chạy paddle
		if (event.type == Event::EventType::KeyPressed)
			if (ball->getIdle()) ball->randomDirection();
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		p1->moveUp();
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		p1->moveDown();
	}
	if (!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S)) {
		p1->stopMoving();
	}

	if (Keyboard::isKeyPressed(Keyboard::I)) {
		p2->moveUp();
	}
	if (Keyboard::isKeyPressed(Keyboard::K)) {
		p2->moveDown();
	}
	if (!Keyboard::isKeyPressed(Keyboard::I) && !Keyboard::isKeyPressed(Keyboard::K)) {
		p2->stopMoving();
	}

	if (Keyboard::isKeyPressed(Keyboard::R)) {
		p1->reset();
		p2->reset();
		ball->reset();
	}
}
void Game::update() {
	timeInterval = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	p1->update(timeInterval);
	p2->update(timeInterval);
	ball->handleCollisions(others);
	ball->update(timeInterval);
}
void Game::render() {
	b->draw();
	ball->draw();
	p1->draw();
	p2->draw();
}