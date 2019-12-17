#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using std::string;

namespace sides {
	enum Side {
		TOP,
		BOTTOM,
		LEFT,
		RIGHT,
		NONE
	};

	inline Side getOppositeSide(Side side) {
		return side == TOP ? BOTTOM :
			side == BOTTOM ? TOP :
			side == LEFT ? RIGHT :
			side == RIGHT ? LEFT :
			NONE;
	}
}

class Entity {
protected:
	const float x;
	const float y;
	Shape* shape;
	RenderWindow* window;

public:
	Entity(RenderWindow* window, float x, float y);

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

	virtual void draw();

	bool isIntersect(Entity &other);

	/**
	* Trả lại tung độ trên
	*
	* @note
	*
	*
	* @return (float) top
	**/
	float getTop();

	/**
	* Trả lại tung độ dưới
	*
	* @note
	*
	*
	* @return (float) bottom
	**/
	float getBottom();

	/**
	* Trả lại hoành độ phải
	*
	* @note
	*
	*
	* @return (float) right
	**/
	float getRight();

	/**
	* Trả lại hoành độ trái
	*
	* @note
	*
	*
	* @return (float) left
	**/
	float getLeft();
};
