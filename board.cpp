#include "board.h"

Board::Board(RenderWindow* window, float x, float y, float width, float height) : Entity(window, x, y) {
	shape = new RectangleShape(Vector2f(width, height));
	setX(x);
	setY(y);

	midLine.setSize(sf::Vector2f((float)2, (float)height));
	midLine.setOrigin(midLine.getSize() / 2.f);
	midLine.setPosition(sf::Vector2f(x + width / (float)2, y + height / (float)2));
	midLine.setFillColor(sf::Color(255, 255, 255, 255 / 2));
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

void Board::draw() {
	Entity::draw();
	window->draw(midLine);
}