#pragma once
#include "PongBall.h"
#include "PongPaddle.h"


#include <string>
using namespace std;

class GamePong :public Window
{
private:
	bool endGame;
	Ball* ball;
	Paddle* player1;
	Paddle* player2;
	sf::RectangleShape midLine;
	int nPlayer; //Số người chơi
	string nameP1 = "PLAYER 1";

public:
	int timeInterval = 0;
	GamePong(int w, int h, int n);
	~GamePong();
	bool isOpenWindow();
	void Winner(Paddle* player);
	void Draw();
	void Input();
	void Logic();
	void Run();
	void reset();
	void BotControl(Paddle*);
	bool isMid(int a, int b, int c);
};
