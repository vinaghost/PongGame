#include "game.h"

Game::Game(int width, int height) : Windows(width, height), endGame(false) {
	srand((unsigned int)time(NULL));

	/*ball = new Ball(w, h);
	player1 = new Paddle(h);
	player2 = new Paddle(h);*/

	/*nPlayer = n;
	if (n == 1) nameP1 = "BOT";*/
}

Game::~Game() {
	//delete ball, player1, player2;
}

void Game::processEvents() {
	while (renderWindow.pollEvent(event)) {
		if (event.type == sf::Event::EventType::Closed)
			renderWindow.close();
	}
}
void Game::update() {
}
void Game::render() {
}