#include "game_screen.h"
#include <vector>

using std::vector;

GameScreen::GameScreen(RenderWindow* window, Setting* setting) : Screen(window, setting), newGame(true), endGame(false) {
	srand((unsigned int)time(NULL));

	b = new Board(window);
	b->setColor(255, 124, 0);
	b->setBackgroundColor(0, 0, 255);

	player = new Paddle(window, b);
	player->setBackgroundColor(255, 0, 0);
	others.push_back(player);

	ball = new Ball(window, b, 20, player);
	ball->setBackgroundColor(0, 255, 0);
	ball->setSetting(setting);

	things = new ItemManager(window, b);

	things->createItem(b);

	score.setRenderWindow(window);
	score.setPosition(100, 10);
}

GameScreen::~GameScreen() {
	delete ball;
	delete player;
}

void GameScreen::processEvents() {
	while (window->pollEvent(event)) {
		//Xử lý khi người dùng nhấn X để thoát
		if (event.type == Event::EventType::Closed)
		{
			loop = false;
			nextScreen = EXIT;
			window->close();
		}
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
		nextScreen = LOSE;
		loop = false;
	}
}
void GameScreen::update() {
	char str[32];
	sprintf_s(str, "[Score: %d]", setting->getScore());
	score.setString(str);

	objects.clear();
	things1.clear();
	things1 = things->spawnedItem();
	for (size_t i = 0; i < others.size(); i++)
	{
		objects.push_back(others[i]);
	}
	for (size_t i = 0; i < things1.size(); i++)
	{
		objects.push_back(things1[i]);
	}
	timeInterval = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	player->update(timeInterval);
	ball->handleCollisions(objects);
	ball->update(timeInterval);
	things->processEvents();
}
void GameScreen::render() {
	b->draw();
	ball->draw();
	player->draw();
	things->draw();
	score.draw();
}
void GameScreen::reset() {
	player->reset();
	ball->reset(player);
	things->createItem(b);
	score.setString("");
	newGame = true;
}

void GameScreen::setWindow(RenderWindow* window) {
	this->window = window;
}