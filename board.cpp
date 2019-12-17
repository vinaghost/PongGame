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
void Board::draw() {
	Entity::draw();
	window->draw(text);
}