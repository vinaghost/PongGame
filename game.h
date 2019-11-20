#ifndef  _GAME_H

#define _GAME_H

#include "windows.h"

class Game : public Windows {
private:
	bool endGame;
	/*Ball* ball;
	Paddle* player1;
	Paddle* player2;*/
	RectangleShape midLine;
	/*int nPlayer; //Số người chơi
	string nameP1 = "PLAYER 1";*/

	int timeInterval = 0;

public:
	Game(int width, int height);
	virtual ~Game();

	bool isOpenWindow();
	//void Winner(Paddle* player);
	void draw();
	void input();
	void logic();
	void run();
	void reset();
	//void BotControl(Paddle*);
	//bool isMid(int a, int b, int c);
};


#endif // ! _GAME_H
