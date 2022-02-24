#pragma once

#include <SFML/Graphics.hpp>

class MoveRectangle : public sf::Drawable
{
private: 
	sf::RectangleShape rectangle; 
public:
	MoveRectangle();
	MoveRectangle(double width, double height, sf::Color color, sf::Vector2f position);
	sf::FloatRect get_bounds();
	void move(sf::RenderWindow *window, sf::Vector2i mousePosition);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

