#include "board.h"

Board::Board(RenderWindow* window, float x, float y, float width, float height) : Entity(window, x, y) {
	shape = new RectangleShape(Vector2f(width, height));
	setX(x);
	setY(y);
}

string Board::getNameClass() {
	return "Board";
}
float Board::getLeft() {
	return shape->getGlobalBounds().left;
}

float Board::getTop() {
	return shape->getGlobalBounds().top;
}

float Board::getRight() {
	return shape->getGlobalBounds().left + shape->getGlobalBounds().width;
}

float Board::getBottom() {
	return shape->getGlobalBounds().top + shape->getGlobalBounds().height;
}