#include "Point.h"
#include <iostream>
#include <ctime>
#include <vector>

Point::Point()
{
}

Point::Point(float width, float height, vector <sf::RectangleShape> rectangles, float snake_width, sf::Texture& texture) {
	rectangle.setSize(sf::Vector2f(snake_width, snake_width));
	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(width / 3, height / 2);
	
	sprite.setTexture(texture);
	sprite.setColor(sf::Color::Red);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(rectangle.getPosition());
	this->width = width;
	this->height = height;
	pick_new_position(rectangles, snake_width);
}

bool Point::free_pos(int x, int y, vector <sf::RectangleShape> rects, float snake_width) {
	rectangle.setPosition(snake_width / 2 + x * snake_width, snake_width / 2 + y * snake_width);
	sprite.setPosition(rectangle.getPosition());
	for (int i = 0; i < rects.size(); i++)
		if (rectangle.getGlobalBounds().intersects(rects.at(i).getGlobalBounds()))
			return false;
	return true;
}

void Point::pick_new_position(vector <sf::RectangleShape> rects, float snake_width) {
	int pickx = 0, picky = 0;
	do	pickx = rand() % 19,
		picky = rand() % 19;
	while (!free_pos(pickx, picky, rects, snake_width));
}

bool Point::collision(sf::FloatRect rect) {
	return rectangle.getGlobalBounds().intersects(rect) ? true : false;
}

void Point::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}