#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using std::string;

class Entity {
protected:
	float x, y;
	Shape* shape;
	Color color, color_background;
	RenderWindow* window;
public:
	Entity(RenderWindow* window);

	virtual ~Entity();

	/**
	* Trả lại tên class
	*
	* @note
	*
	*
	* @noreturn (string) tên Class
	**/
	virtual string getNameClass() = 0;

	/**
	* Gán tọa độ x của Entity
	*
	* @note
	*
	* @param x hoành độ
	*
	* @noreturn
	**/
	virtual void setX(float x);
	/**
	* Gán tọa độ y của Entity
	*
	* @note
	*
	*
	* @noreturn
	**/
	virtual void setY(float y);
	/**
	* Gán màu outline của Entity
	*
	* @note mã màu RGBA
	*
	* @param red : "độ" đỏ
	* @param blue : "độ" xanh (dương) [lam]
	* @param green : "độ" xanh ( lá ) [lục]
	* @param red : "độ" đỏ
	*
	* @noreturn
	**/
	void setColor(int red, int green, int blue, int alpha = 255);

	/**
	* Gán màu nền của Entity
	*
	* @note mã màu RGBA
	*
	* @param red : "độ" đỏ
	* @param blue : "độ" xanh (dương) [lam]
	* @param green : "độ" xanh ( lá ) [lục]
	* @param red : "độ" đỏ
	*
	* @noreturn
	**/
	void setBackgroundColor(int red, int green, int blue, int alpha = 255);

	/**
	* Trả lại tọa độ x của Entity
	*
	* @note
	*
	*
	* @return (int) x
	**/
	float getX();
	/**
	* Trả lại tọa độ y của Entity
	*
	* @note
	*
	*
	* @return (int) y
	**/
	float getY();

	/**
	* Trả lại màu outline của Entity
	*
	* @note
	*
	*
	* @return (sf::Color) color
	**/
	Color getColor();
	/**
	* Trả lại màu nền của Entity
	*
	* @note
	*
	*
	* @return (sf::Color) color_background
	**/
	Color getBackgroundColor();

	void draw();
};
