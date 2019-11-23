#include "board.h"

Board::Board(float width, float height, RenderWindow* window) : Entity(window) {
	shape = new RectangleShape(Vector2f(width, height));
}

Board::~Board() {
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