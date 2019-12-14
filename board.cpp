#include "board.h"

Board::Board(RenderWindow* window) : Entity(window, default_x, default_y) {
	shape = new RectangleShape(Vector2f(default_width, default_height));
	setX(default_x);
	setY(default_y);
	font.loadFromFile("Resources/Montserrat-BlackItalic.ttf");
	text.setFont(font);
	text.setString("Brick Game");
	text.setPosition(350, 100);

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
	window->draw(text);
}