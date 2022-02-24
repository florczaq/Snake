#pragma once
#include <SFML/Graphics.hpp>

class SnakeHead : public sf::Drawable
{
private:
	sf::RectangleShape rectangle;
	sf::Keyboard::Key dir = sf::Keyboard::S;
	sf::Color headColor = sf::Color(72, 34, 124);
	float ww = 0, wh = 0;
	int speed = 1;	

	void edge();
public :
	SnakeHead();
	SnakeHead(float wwidth, float wheight);
	void move();
	bool changeDirection(sf::Keyboard::Key direction);
	sf::RectangleShape get_shape();
	sf::Vector2f get_pos();
	void set_color(sf::Color color);
	sf::Color getColor();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

