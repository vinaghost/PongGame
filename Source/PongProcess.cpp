#include "Pong.h"

GamePong::GamePong(int w, int h)
{
	srand(time(NULL));
	endGame = false;
	score1 = score2 = 0;
	width = w; height = h;
	renderWindow.create(sf::VideoMode(w, h), "GAME PONG!");
	ball = new Ball(w, h);
	player1 = new Paddle(h);
	player2 = new Paddle(h);
	midLine.setSize(sf::Vector2f(2,h));
	midLine.setOrigin(midLine.getSize()/2.f);
	midLine.setPosition(sf::Vector2f(w/2,h/2));
	midLine.setFillColor(sf::Color(255,255,255,255/2));
}

GamePong::~GamePong()
{
	delete ball, player1, player2;
}

void GamePong::ScoreUp(Paddle* player)
{
	 if (player == player1)
		 score1++;
	 else if (player == player2)
		 score2++;

	delete ball; 
	ball = new Ball(width, height);

	player1->Reset();
	player2->Reset();
}
 
void GamePong :: Input()
{
	ball->Move(timeInterval);
	int player1y = player1->getY();
	int player2y = player2->getY();
	
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if (player1y - Paddle::h/2 > 0)
			player1->moveUp(timeInterval);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (player2y - Paddle::h/2 > 0)
			player2->moveUp(timeInterval);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if (player1y + Paddle::h/2 < height)
			player1->moveDown(timeInterval);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (player2y + Paddle::h/2 < height)
			player2->moveDown(timeInterval);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		endGame = true;
}
 
void GamePong:: Logic()
{
        int ballx = ball->getX();
        int bally = ball->getY();
        int player1y = player1->getY();
        int player2y = player2->getY();
 
        //left paddle
        if (ballx - Ball::r <= Paddle::w)
            if (isMid(player1y - Paddle::h/2 , bally, player1y + Paddle::h/2)){
                ball->reflect(LEFT);
				ball->speedUp(0.1);
				while (ball->getX() - Ball::r <= Paddle::w)
					ball->Move(timeInterval);
			}
 
        //right paddle
    	if (ballx + Ball::r >= width - Paddle::w)
	        if (isMid(player2y - Paddle::h/2 , bally, player2y + Paddle::h/2)){
                ball->reflect(RIGHT);
				ball->speedUp(0.1);
				while (ball->getX() + Ball::r >= width - Paddle::w)
					ball->Move(timeInterval);
			}
 
        //bottom wall
        if (bally + Ball::r >= height){
            ball->reflect(DOWN);
			while (ball->getY() + Ball::r >= height)
					ball->Move(timeInterval);
		}
        //top wall
        if (bally - Ball::r <= 0){
            ball->reflect(UP);
			while (ball->getY() - Ball::r <= 0)
					ball->Move(timeInterval);
		}//right wall
        if (ballx + Ball::r >= width)
            ScoreUp(player1);
        //left wall
        if (ballx - Ball::r <= 0)
            ScoreUp(player2);
 }
 void GamePong::Run()
 {
	while(renderWindow.isOpen()){
    	
			//Kiểm tra toàn bộ event từ vòng lặp trước
    		while (renderWindow.pollEvent(event)){
    			//Xử lý khi người dùng nhấn X để thoát
      			if (event.type == sf::Event::EventType::Closed)
        		renderWindow.close();
				//Xử lý người dùng nhấn phím bất kỳ để chạy paddle
				if (event.type == sf::Event::EventType::KeyPressed && ball->idle)
					ball->randomDirection();
    		}

		if (!endGame){
    		Draw();

			//Tính khoảng thời gian render giữa 2 frame
			timeInterval = clock.getElapsedTime().asMicroseconds();
			clock.restart();

			Input();
			Logic();
		}
  	}
		 
 }
 
