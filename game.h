#ifndef  _GAME_H

#define _GAME_H

#include "windows.h"

#include "board.h"
#include "ball.h"
#include "paddle.h"

class Game : public Windows {
private:
	bool endGame;
	Int64 timeInterval;
	/*int nPlayer; //Số người chơi
	string nameP1 = "PLAYER 1";*/

	const int width = 500;
	const int height = 400;
	Board *b;
	Ball* ball;
	Paddle* p1;
	Paddle* p2;

	std::vector<Entity*> others;

	void processEvents();
	void update();
	void render();

public:
	Game(int width, int height);
	virtual ~Game();

	//void Winner(Paddle* player);
	//void BotControl(Paddle*);
	//bool isMid(int a, int b, int c);
};

#endif // ! _GAME_H
