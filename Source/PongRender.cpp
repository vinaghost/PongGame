#include "Pong.h"

void GamePong::Draw()
{
	//while (clock.getElapsedTime().asMicroseconds() < (1000000/FPS));
	renderWindow.clear();
	renderWindow.draw(midLine);
	ball->shape.setPosition(ball->getX(),ball->getY());
	player1->shape.setPosition(Paddle::w,player1->getY());
	player2->shape.setPosition(width - Paddle::w,player2->getY());
	renderWindow.draw(ball->shape);
	renderWindow.draw(player1->shape);
	renderWindow.draw(player2->shape);
	renderWindow.display();
	//clock.restart();
}