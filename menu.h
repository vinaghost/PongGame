#pragma once

#include "SFML/Graphics.hpp"

#include <vector>
using namespace std;
using namespace sf;

#define NUM_BUTTONS 3

class Menu
{
private:
	vector<string> S;
	vector<Text> buttons;
	Font font;
	float x, y;
	RenderWindow* window;
public:
	Menu(RenderWindow* window, float x, float y);
	~Menu();

	/**
	* Gán hoành độ vị trí đầu x của Menu
	*
	* @note
	*
	* @param x hoành độ vị trí đầu
	*
	* @noreturn
	**/
	void setX(float x);
	/**
	* Gán tung độ vị trí đầu y của Menu
	*
	* @note
	*
	* @param y tung độ vị trí đầu
	*
	* @noreturn
	**/
	void setY(float y);
	/**
	* Trả hoành độ vị trí đầu x của Menu
	*
	* @note
	*
	*
	* @return (float) x
	**/
	float getX();
	/**
	* Trả tung độ vị trí đầu y của Menu
	*
	* @note
	*
	*
	* @return (float) y
	**/
	float getY();
	/**
	* Tạo tên nút trên Menu
	*
	* @note
	*
	* @param a tên của nút
	*
	* @return (float) x
	**/
	void setButtons(string a);
	/**
	* Tạo các nút trên Menu
	*
	* @note
	*
	* @param 
	*
	* @return (float) x
	**/
	void setMenu();
	/**
	* Vẽ Menu lên màn hình window
	*
	* @note
	*
	* @param window
	*
	* @return
	**/
	void draw();
	/**
	* Xét Mouse có trên màn hình window hay không
	*
	* @note
	*
	* @param window
	* @param text 
	*
	* @return (bool) True/False
	**/
	bool isTextClicked(Text text);
	/**
	* Xử lý Mouse bấm trên Menu
	*
	* @note
	*
	* @param window
	*
	* @noreturn 
	**/
	void handleInput();
	/**
	* Trình chiếu window
	*
	* @note
	*
	* @param window
	*
	* @noreturn
	**/
	void windowDisplay();


};