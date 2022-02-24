#pragma once

#include<SFML/Graphics.hpp>

class Mouse_cursor : public sf::Drawable
{
private:
	sf::CircleShape circle;
public:
	Mouse_cursor();
	void set_position(sf::Vector2f position);
	bool pressed(sf::FloatRect button_rect);
	sf::FloatRect get_bounds();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};