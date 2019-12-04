#include "game.h"
#include <vector>

using std::vector;

Game::Game(RenderWindow* window) : Screen(window), newGame(true), endGame(false) {
	srand((unsigned int)time(NULL));

	b = new Board(window);
	b->setColor(255, 124, 0);
	b->setBackgroundColor(0, 0, 255);

	ball = new Ball(window, b, 20);
	ball->setBackgroundColor(0, 255, 0);

	p1 = new Paddle(window, b, winners::LEFT);
	p1->setBackgroundColor(255, 0, 0);
	others.push_back(p1);

	p2 = new Paddle(window, b, winners::RIGHT);
	p2->setBackgroundColor(255, 0, 0);
	others.push_back(p2);
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
			if (ball->getIdle() && newGame) {
				ball->randomDirection();
				newGame = false;
			}
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
		reset();
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		nextScreen = PAUSE;
		loop = false;
	}
}
void Game::update() {
	timeInterval = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	p1->update(timeInterval);
	p2->update(timeInterval);
	ball->update(timeInterval);
	ball->handleCollisions(others);
}
void Game::render() {
	b->draw();
	ball->draw();
	p1->draw();
	p2->draw();
}
void Game::reset() {
	p1->reset();
	p2->reset();
	ball->reset();

	newGame = true;
}

void Game::setWindow(RenderWindow* window) {
	this->window = window;
}