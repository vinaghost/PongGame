#include "Pong.h"

void GamePong::Draw()
{
	//while (clock.getElapsedTime().asMicroseconds() < (1000000/FPS));
	renderWindow.clear();

	sf::Font font;
	font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");


	sf::Text P1, P2;
	P1.setFont(font);
	
	P1.setFillColor(sf::Color(255,255,255,255*0.3));


	if (nPlayer == 1) P1.setCharacterSize(height/5); 
	else P1.setCharacterSize(height/3);
	

	if (nPlayer == 1) P1.setString("BOT");
	else P1.setString("P1");


	//canh giữa
	sf::FloatRect bound1(P1.getLocalBounds());
    P1.setPosition(width/4 - (bound1.left + bound1.width/2), height/2 - (bound1.top + bound1.height/2));
	renderWindow.draw(P1); 

	P2.setFont(font);
	P2.setCharacterSize(height/3);
	P2.setFillColor(sf::Color(255,255,255,255*0.3));
	P2.setString("P2");
	sf::FloatRect bound2(P2.getLocalBounds());
    P2.setPosition(width*3/4 - (bound2.left + bound2.width/2), height/2 - (bound2.top + bound2.height/2));
	renderWindow.draw(P2); 



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