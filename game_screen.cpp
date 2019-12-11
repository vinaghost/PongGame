#include "game_screen.h"
#include <vector>

using std::vector;

GameScreen::GameScreen(RenderWindow* window) : Screen(window), newGame(true), endGame(false) {
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

GameScreen::~GameScreen() {
	delete ball;
	delete p1;
	delete p2;
}

void GameScreen::processEvents() {
	while (window->pollEvent(event)) {
		//Xử lý khi người dùng nhấn X để thoát
		if (event.type == Event::EventType::Closed)
			window->close();
	}
	if (Keyboard::isKeyPressed(Keyboard::F)) {
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

	switch (ball->getWinner()) {
	case winners::LEFT:
		break;
	case winners::RIGHT:
		break;
	case winners::NONE:
		break;
	}
}
void GameScreen::update() {
	timeInterval = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	p1->update(timeInterval);
	p2->update(timeInterval);
	ball->update(timeInterval);
	ball->handleCollisions(others);
}
void GameScreen::render() {
	b->draw();
	ball->draw();
	p1->draw();
	p2->draw();
}
void GameScreen::reset() {
	p1->reset();
	p2->reset();
	ball->reset();

	newGame = true;
}

void GameScreen::setWindow(RenderWindow* window) {
	this->window = window;
}