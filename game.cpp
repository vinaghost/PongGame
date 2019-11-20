#include "game.h"

Game::Game(int width, int height) : Windows(width, height) {
	srand((unsigned int)time(NULL));
	endGame = false;
	renderWindow.create(sf::VideoMode(width, height), "GAME PONG!");
	/*ball = new Ball(w, h);
	player1 = new Paddle(h);
	player2 = new Paddle(h);*/
	midLine.setSize(sf::Vector2f((float)2, (float)height));
	midLine.setOrigin(midLine.getSize() / 2.f);
	midLine.setPosition(sf::Vector2f(width / (float)2, height / (float)2));
	midLine.setFillColor(sf::Color(255, 255, 255, 255 / 2));
	/*nPlayer = n;
	if (n == 1) nameP1 = "BOT";*/
}

Game::~Game() {
	//delete ball, player1, player2;
}


bool Game::isOpenWindow(){
	return renderWindow.isOpen();
}

/*bool Game::isMid(int a, int b, int c)
{
	if (a <= b && c >= b) return true;
	return false;
}*/
/*
void Game::Winner(Paddle* player)
{
	sf::Font dFont;
	dFont.loadFromFile("Resources/Montserrat-Black.ttf");
	sf::RectangleShape Cover(sf::Vector2f(width, height));
	Cover.setFillColor(sf::Color(255, 255, 255, 255 * 0.8));
	renderWindow.draw(Cover);
	sf::Text WinnerName;

	WinnerName.setFont(dFont);
	WinnerName.setCharacterSize(height / 6);
	WinnerName.setFillColor(sf::Color::Black);
	if (player == player1)
		WinnerName.setString((nameP1 + " WIN!").c_str());
	else WinnerName.setString("PLAYER 2 WIN!");
	sf::FloatRect bound1(WinnerName.getLocalBounds());
	WinnerName.setPosition(width / 2 - (bound1.left + bound1.width / 2), height / 2 - (bound1.top + bound1.height / 2));
	renderWindow.draw(WinnerName);
	renderWindow.display();
	endGame = true;
}
*/
void Game::input() {
	/*ball->Move(timeInterval);

	int player1y = player1->getY();
	int player2y = player2->getY();

	if (nPlayer == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			if (player1y - Paddle::h / 2 > 0)
				player1->moveUp(timeInterval);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			if (player1y + Paddle::h / 2 < height)
				player1->moveDown(timeInterval);
	}
	else BotControl(player1);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (player2y - Paddle::h / 2 > 0)
			player2->moveUp(timeInterval);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (player2y + Paddle::h / 2 < height)
			player2->moveDown(timeInterval);*/
}

void Game::logic() {
	//int ballx = ball->getX();
	//int bally = ball->getY();
	//int player1y = player1->getY();
	//int player2y = player2->getY();

	////left paddle
	//if (ballx - Ball::r <= Paddle::w)
	//	if (isMid(player1y - Paddle::h / 2, bally, player1y + Paddle::h / 2)) {
	//		ball->reflect(LEFT);
	//		ball->speedUp(0.1);
	//	}

	////right paddle
	//if (ballx + Ball::r >= width - Paddle::w)
	//	if (isMid(player2y - Paddle::h / 2, bally, player2y + Paddle::h / 2)) {
	//		ball->reflect(RIGHT);
	//		ball->speedUp(0.1);
	//	}

	////bottom wall
	//if (bally + Ball::r >= height) {
	//	ball->reflect(DOWN);
	//}
	////top wall
	//if (bally - Ball::r <= 0) {
	//	ball->reflect(UP);
	//}

	////right wall
	//if (ballx + Ball::r >= width) Winner(player1);
	////left wall
	//if (ballx - Ball::r <= 0) Winner(player2);
}

void Game::run() {
	while (renderWindow.isOpen()) {

		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();

			/*if (event.type == sf::Event::EventType::KeyPressed)
				if (ball->idle) ball->randomDirection();
				else if (endGame) return;*/
		}

		if (!endGame) {
			draw();

			//Tính khoảng thời gian render giữa 2 frame
			timeInterval = (int)clock.getElapsedTime().asMicroseconds();
			clock.restart();

			input();
			logic();
		}
	}

}

void Game::reset() {
	/*delete ball;
	endGame = false;
	ball = new Ball(width, height);
	player1->reset();
	player2->reset();*/


	while (renderWindow.pollEvent(event)) {}


}

//void Game::BotControl(Paddle* p) {
//	if (ball->getY() < p->getY()) {
//		if (p->getY() - Paddle::h / 2 > 0)
//			p->moveUp(timeInterval);
//	}
//	else if (p->getY() + Paddle::h / 2 < height)
//		p->moveDown(timeInterval);
//}

void Game::draw() {
	//while (clock.getElapsedTime().asMicroseconds() < (1000000/FPS));
	renderWindow.clear();

	sf::Font font;
	font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");


	sf::Text P1, P2;
	P1.setFont(font);

	P1.setFillColor(sf::Color(255, 255, 255, (sf::Uint8)(255 * 0.3)));


	//if (nPlayer == 1) P1.setCharacterSize(height / 5);
	//else 
	P1.setCharacterSize(height / 3);


	//if (nPlayer == 1) P1.setString("BOT");
	//else 
	P1.setString("P1");


	//canh giữa
	sf::FloatRect bound1(P1.getLocalBounds());
	P1.setPosition(width / 4 - (bound1.left + bound1.width / 2), height / 2 - (bound1.top + bound1.height / 2));
	renderWindow.draw(P1);

	P2.setFont(font);
	P2.setCharacterSize(height / 3);
	P2.setFillColor(sf::Color(255, 255, 255, sf::Uint8(255 * 0.3)));
	P2.setString("P2");
	sf::FloatRect bound2(P2.getLocalBounds());
	P2.setPosition(width * 3 / 4 - (bound2.left + bound2.width / 2), height / 2 - (bound2.top + bound2.height / 2));
	renderWindow.draw(P2);

	renderWindow.draw(midLine);

	/*ball->shape.setPosition(ball->getX(), ball->getY());

	player1->shape.setPosition(Paddle::w, player1->getY());

	player2->shape.setPosition(width - Paddle::w, player2->getY());
	
	renderWindow.draw(ball->shape);
	renderWindow.draw(player1->shape);
	renderWindow.draw(player2->shape);
	*/

	renderWindow.display();
	//clock.restart();
}