#include "SnakeHead.h"


SnakeHead::SnakeHead()
{
}

SnakeHead::SnakeHead(float width, float height) {
	rectangle.setSize(sf::Vector2f(width / 20 -10, width / 20 -10));
	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
	rectangle.setFillColor(headColor);
	rectangle.setPosition(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(1);
	this->ww = width, this->wh = height;
	speed = rectangle.getSize().x;
}

void SnakeHead::move()
{
	sf::Vector2f pos = rectangle.getPosition();
	switch (dir) {
	case sf::Keyboard::W:
		rectangle.setPosition(pos.x, pos.y - speed);
		break;
	case sf::Keyboard::A:
		rectangle.setPosition(pos.x - speed, pos.y);
		break;
	case sf::Keyboard::S:
		rectangle.setPosition(pos.x, pos.y + speed);
		break;
	case sf::Keyboard::D:
		rectangle.setPosition(pos.x + speed, pos.y);
		break;
	}
	edge();
}

bool SnakeHead::changeDirection(sf::Keyboard::Key direction) {
	switch (direction) {
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		if (dir != sf::Keyboard::S) dir = sf::Keyboard::W;
		else return false;
		return true;
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		if (dir != sf::Keyboard::W) dir = sf::Keyboard::S;
		else return false;
		return true;
		break;
	case sf::Keyboard::A:
	case sf::Keyboard::Left:
		if (dir != sf::Keyboard::D) dir = sf::Keyboard::A;
		else return false;
		return true;
		break;
	case sf::Keyboard::D:
	case sf::Keyboard::Right:
		if (dir != sf::Keyboard::A) dir = sf::Keyboard::D;
		else return false;
		return true;
		break;
	}
	return false;
}



void SnakeHead::edge() {
	sf::Vector2f pos = rectangle.getPosition();
	if (pos.x > ww)
		rectangle.setPosition(rectangle.getSize().x / 2, pos.y);
	if (pos.x < 0)
		rectangle.setPosition(ww - rectangle.getSize().x / 2, pos.y);
	if (pos.y > wh)
		rectangle.setPosition(pos.x, rectangle.getSize().y / 2);
	if (pos.y < 0)
		rectangle.setPosition(pos.x, wh - rectangle.getSize().y / 2);
}

sf::RectangleShape SnakeHead::get_shape()
{
	return rectangle;
}

sf::Vector2f SnakeHead::get_pos()
{
	return rectangle.getPosition();
}

void SnakeHead::set_color(sf::Color color)
{
	headColor = color;
	rectangle.setFillColor(color);
}

sf::Color SnakeHead::getColor()
{
	return rectangle.getFillColor();
}

void SnakeHead::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
}