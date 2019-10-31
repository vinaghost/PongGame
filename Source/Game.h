#pragma once

#include "Default.h"

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };
class cBall
{
private:
	int x, y;
	int originalX, originalY;
	eDir direction;
public:
	cBall(int posX, int posY);
	void Reset();
	void changeDirection(eDir d);
	void randomDirection();
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline eDir getDirection() { return direction; }
	void Move();
	friend ostream& operator<<(ostream& o, cBall c);
	
};
class cPaddle
{
private:
	int x, y;
	int originalX, originalY;
public:
	cPaddle();
	cPaddle(int posX, int posY) : cPaddle()
	{
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
	};
	inline void Reset() { x = originalX; y = originalY; }
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline void moveUp() { y--; }
	inline void moveDown() { y++; }
	friend ostream& operator<<(ostream& o, cPaddle c);
	
};
class cGameManger
{
private:
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	cBall* ball;
	cPaddle* player1;
	cPaddle* player2;
public:
	cGameManger(int w, int h);
	~cGameManger();
	void ScoreUp(cPaddle* player);
	void Draw();
	void Input();
	void Logic();
	void Run();
};