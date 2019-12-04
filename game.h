#ifndef  _GAME_H

#define _GAME_H

#include "screen.h"

#include "board.h"
#include "ball.h"
#include "paddle.h"

class Game : public Screen {
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
	Paddle* p1;
	Paddle* p2;

	std::vector<Entity*> others;
protected:
	void processEvents();
	void update();
	void render();
	void reset();
public:
	Game(RenderWindow* window);
	virtual ~Game();

	void setWindow(RenderWindow* window);
};

#endif // ! _GAME_H
