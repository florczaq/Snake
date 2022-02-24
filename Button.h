#pragma once

#include <SFML/Graphics.hpp>

using std::string;

class Button : public sf::Drawable
{
private :
	sf::RectangleShape rectangle;
	sf::Text text;
	sf::Color col;
public :
	Button();
	Button(sf::Font &font, double width, double height, string text, sf::Color color, sf::Vector2f position);
	Button(sf::Font &font, double width, double height, string text, sf::Color color, sf::Vector2f position, float charSize, sf::Color textColor);
	sf::FloatRect get_bounds();
	void hover(bool hovered);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

