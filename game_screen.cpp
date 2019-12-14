#include "game_screen.h"
#include <vector>

using std::vector;

GameScreen::GameScreen(RenderWindow* window) : Screen(window), newGame(true), endGame(false) {
	srand((unsigned int)time(NULL));

	b = new Board(window);
	b->setColor(255, 124, 0);
	b->setBackgroundColor(0, 0, 255);

	player = new Paddle(window, b);
	player->setBackgroundColor(255, 0, 0);
	others.push_back(player);

	ball = new Ball(window, b, 20, player);
	ball->setBackgroundColor(0, 255, 0);
}

GameScreen::~GameScreen() {
	delete ball;
	delete player;
}

void GameScreen::processEvents() {
	while (window->pollEvent(event)) {
		//Xử lý khi người dùng nhấn X để thoát
		if (event.type == Event::EventType::Closed)
			window->close();
	}

	if (Keyboard::isKeyPressed(Keyboard::F)) {
		if (ball->getIdle() && newGame) {
			ball->getStart();
			newGame = false;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		player->moveRight();
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		player->moveLeft();
	}
	if (!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)) {
		player->stopMoving();
	}

	if (Keyboard::isKeyPressed(Keyboard::R)) {
		reset();
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		nextScreen = PAUSE;
		loop = false;
	}

	if (ball->getState()) {
		nextScreen = LEFT_WIN;
		loop = false;
	}
}
void GameScreen::update() {
	timeInterval = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	player->update(timeInterval);
	ball->update(timeInterval);
	ball->handleCollisions(others);
}
void GameScreen::render() {
	b->draw();
	ball->draw();
	player->draw();
}
void GameScreen::reset() {
	player->reset();
	ball->reset(player);

	newGame = true;
}

void GameScreen::setWindow(RenderWindow* window) {
	this->window = window;
}