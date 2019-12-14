﻿#ifndef  _GAME_H

#define _GAME_H

#include "screen.h"

#include "board.h"
#include "ball.h"
#include "paddle.h"
#include "ItemManager.h"

class GameScreen : public Screen {
private:
	Event event;
	Clock clock;
	bool endGame;
	bool newGame;
	Int64 timeInterval;
	/*int nPlayer; //Số người chơi
	string nameP1 = "PLAYER 1";*/

	Board* b;
	Ball* ball;
	Paddle* player;

	ItemManager* things;

	std::vector<Entity*> others;
	std::vector<Entity*> objects;
	std::vector<Item*> things1;
protected:
	void processEvents();
	void update();
	void render();
	void reset();
public:
	GameScreen(RenderWindow* window);
	virtual ~GameScreen();

	void setWindow(RenderWindow* window);
};

#endif // ! _GAME_H