#pragma once
#include<SFML/Graphics.hpp>

class Pause_button : public sf::Drawable
{
private:
	sf::RectangleShape rectangle;
	
public:
	Pause_button(sf::Vector2f size, sf::Color color, sf::Vector2f position);
	Pause_button();
	void hover(bool hovered);
	sf::FloatRect get_bounds();
	sf::Vector2f get_size();
	sf::Vector2f get_position();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

