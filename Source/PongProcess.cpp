#include "Pong.h"

GamePong::GamePong(int w, int h, int n)
{
	srand(time(NULL));
	endGame = false;
	width = w; height = h;
	renderWindow.create(sf::VideoMode(w, h), "GAME PONG!");
	ball = new Ball(w, h);
	player1 = new Paddle(h);
	player2 = new Paddle(h);
	midLine.setSize(sf::Vector2f(2,h));
	midLine.setOrigin(midLine.getSize()/2.f);
	midLine.setPosition(sf::Vector2f(w/2,h/2));
	midLine.setFillColor(sf::Color(255,255,255,255/2));
	nPlayer = n;
	if (n == 1) nameP1 = "BOT";
}

GamePong::~GamePong()
{
	delete ball, player1, player2;
}

void GamePong::Winner(Paddle* player)
{
	sf::Font dFont;
	dFont.loadFromFile("Resources/Montserrat-Black.ttf");
	sf::RectangleShape Cover(sf::Vector2f(width, height));
	Cover.setFillColor(sf::Color(255,255,255,255*0.8));
	renderWindow.draw(Cover);
	sf::Text WinnerName;

	WinnerName.setFont(dFont);
	WinnerName.setCharacterSize(height/6);
	WinnerName.setFillColor(sf::Color::Black);
	if (player == player1)
		WinnerName.setString((nameP1 + " WIN!").c_str());
	else WinnerName.setString("PLAYER 2 WIN!");
	sf::FloatRect bound1(WinnerName.getLocalBounds());
	WinnerName.setPosition(width/2 - (bound1.left + bound1.width/2), height/2 - (bound1.top + bound1.height/2));
	renderWindow.draw(WinnerName); 
	renderWindow.display();
	endGame = true;
}
 
void GamePong::Input()
{
	ball->Move(timeInterval);
	int player1y = player1->getY();
	int player2y = player2->getY();
	
	if (nPlayer == 2){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			if (player1y - Paddle::h/2 > 0)
				player1->moveUp(timeInterval);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			if (player1y + Paddle::h/2 < height)
				player1->moveDown(timeInterval);
	} else BotControl(player1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (player2y - Paddle::h/2 > 0)
			player2->moveUp(timeInterval);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (player2y + Paddle::h/2 < height)
			player2->moveDown(timeInterval);
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
			//	while (ball->getX() - Ball::r <= Paddle::w)
			//		ball->Move(timeInterval);
			}
 
        //right paddle
    	if (ballx + Ball::r >= width - Paddle::w)
	        if (isMid(player2y - Paddle::h/2 , bally, player2y + Paddle::h/2)){
                ball->reflect(RIGHT);
				ball->speedUp(0.1);
			//	while (ball->getX() + Ball::r >= width - Paddle::w)
			//		ball->Move(timeInterval);
			}
 
        //bottom wall
        if (bally + Ball::r >= height){
            ball->reflect(DOWN);
			//while (ball->getY() + Ball::r >= height)
			//		ball->Move(timeInterval);
		}
        //top wall
        if (bally - Ball::r <= 0){
            ball->reflect(UP);
			//while (ball->getY() - Ball::r <= 0)
			//		ball->Move(timeInterval);
		}
		
		//right wall
        if (ballx + Ball::r >= width) Winner(player1);
        //left wall
        if (ballx - Ball::r <= 0) Winner(player2);
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
				if (event.type == sf::Event::EventType::KeyPressed)
					if (ball->idle) ball->randomDirection();
					else if (endGame) return;
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
 
 void GamePong::reset(){
	delete ball;
	endGame = false;
	ball = new Ball(width, height);
	player1->reset();
	player2->reset();
	while (renderWindow.pollEvent(event)){}
 }

void GamePong::BotControl(Paddle* p){
	if (ball->getY() < p->getY()){
			if (p->getY() - Paddle::h/2 > 0)
				p->moveUp(timeInterval);
	} else if (p->getY() + Paddle::h/2 < height)
				p->moveDown(timeInterval);
}