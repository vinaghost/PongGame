#include "board.h"

Board::Board(RenderWindow* window) : Entity(window, default_x, default_y) {
	shape = new RectangleShape(Vector2f(default_width, default_height));
	setX(default_x);
	setY(default_y);

	midLine.setSize(Vector2f((float)2, (float)default_height));
	midLine.setOrigin(midLine.getSize() / 2.f);
	midLine.setPosition(Vector2f(default_x + default_width / (float)2, default_y + default_height / (float)2));
	midLine.setFillColor(Color(255, 255, 255, 255 / 2));
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