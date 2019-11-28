#ifndef  _GAME_H

#define _GAME_H

#include "windows.h"

class Game : public Windows {
private:
	bool endGame;
	/*Ball* ball;
	Paddle* player1;
	Paddle* player2;*/
	/*int nPlayer; //Số người chơi
	string nameP1 = "PLAYER 1";*/

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
