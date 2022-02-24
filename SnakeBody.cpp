#include "SnakeBody.h"

#include <iostream>

sf::RectangleShape SnakeBody::new_rect(sf::Vector2f position)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(width / 20, width / 20));
	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
	rectangle.setFillColor(bodyColor);
	rectangle.setPosition(position);
	return rectangle;
}
 
SnakeBody::SnakeBody(){}

SnakeBody::SnakeBody(float width, float height, sf::Vector2f pos)
{
	this->width = width;
	this->height = height;
	old_pos = pos;
}

void SnakeBody::afterMove(sf::Vector2f pos)
{
	if (rectangles.size() > 1) 
		rectangles.erase(rectangles.begin());

	rectangles.push_back(new_rect(old_pos));

	old_pos = pos;
}

void SnakeBody::add_body()
{
	if(rectangles.size()>=1)
		rectangles.push_back(new_rect(rectangles.at(rectangles.size()-1).getPosition()));
}

void SnakeBody::set_color(sf::Color color)
{
	bodyColor = color;
}

int SnakeBody::getVectorSize()
{
	return rectangles.size();
}

bool SnakeBody::body_colision(sf::FloatRect head)
{
	for (int i = 0; i < rectangles.size(); i++)
		if (rectangles.at(i).getGlobalBounds().intersects(head))
			return true;
	return false;
}

vector<sf::RectangleShape> SnakeBody::get_shapes()
{
	return rectangles;
}

void SnakeBody::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < rectangles.size(); i++) {
		target.draw(rectangles.at(i));
	}
}
