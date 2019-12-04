#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include <string>

using namespace sf;
using std::vector;
using std::string;

class Menu {
protected:
	vector<string> nameItem;
	vector<Text> buttons;
	Font font;
	Event event;

	RenderWindow* window;
	float x, y;

	int choice;

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
	* @param nameButton tên của nút
	*
	* @noreturn
	**/
	void addButtons(string nameButton);

	/**
	* Khởi tạo vị trí các nút
	*
	* @note dựa trên [x, y], các nút được xếp dọc
	*
	* @param distance - Khoảng cách giữa các nút
	*
	* @noreturn
	**/
	void initMenu(int distance);

	/**
	* Vẽ Menu lên màn hình window
	*
	* @note
	*
	*
	* @noreturn
	**/
	void draw();

	/**
	* Check chuột ở trong hitbox của text
	*
	* @note
	*
	* @param text
	*
	* @return (bool)
	**/
	bool isTextClicked(Text text);

	void processEvents();

	/**
	* Trả về lựa chọn item
	*
	* @note
	*
	*
	* @return (int) item được chọn
	**/
	int getChoice();
};