#pragma once

#include "Default.h"
enum eDir { LEFT = 1, UP = 2, DOWN = 3, RIGHT = 4 };
class Ball
{
private:
	sf::Vector2f v;
	float x, y;
	eDir direction;
	
public:
	bool idle = true;
	static int const initspeed = 1; //Pixel per frame
	static int const r = 10;
	sf::CircleShape shape;
	Ball(int screenX, int screenY);
	void speedUp(float);
	void reflect(eDir);
	void randomDirection();
	inline float getX() { return x; }
	inline float getY() { return y; }
	void Move(int microsec);
};

class Paddle
{
private:
	float y;
	int originalY;
	
public:
	static int const speed = 10;
	static int const w = 10, h = 60;
	sf::RectangleShape shape;
	Paddle(int screenY);
	inline void Reset() {y = originalY; }
	inline int getY() { return y; }
	inline void moveUp(int timeInterval) { y-=(speed*timeInterval/(1000000.0/FPS)); }
	inline void moveDown(int timeInterval) { y+=(speed*timeInterval/(1000000.0/FPS)); }
	
};

class GamePong:public Window
{
private:
	int score1, score2;
	bool endGame;
	Ball* ball;
	Paddle* player1;
	Paddle* player2;
	
public:
	int timeInterval = 0;
	GamePong(int w, int h);
	~GamePong();
	void ScoreUp(Paddle* player);
	void Draw();
	void Input();
	void Logic();
	void Run();
};