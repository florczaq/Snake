#include "Pause_button.h"

Pause_button::Pause_button(sf::Vector2f size, sf::Color color, sf::Vector2f position)
{
	rectangle.setSize(size);
	rectangle.setPosition(position);
	rectangle.setFillColor(color);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(2);
	rectangle.setOrigin(size.x/2, size.y/2);
}

Pause_button::Pause_button()
{
}

void Pause_button::hover(bool hovered)
{
	if (hovered) {
		rectangle.setScale(sf::Vector2f(1.1, 1.1));
		rectangle.setOutlineColor(sf::Color::White);
		rectangle.setOutlineThickness(3);
	}
	else {
		rectangle.setScale(sf::Vector2f(1, 1));
		rectangle.setOutlineColor(sf::Color::Black);
		rectangle.setOutlineThickness(2);

	}
}

sf::FloatRect Pause_button::get_bounds()
{
	return rectangle.getGlobalBounds();
}

sf::Vector2f Pause_button::get_size()
{
	return rectangle.getSize();
}

sf::Vector2f Pause_button::get_position()
{
	return rectangle.getPosition();
}

void Pause_button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
}
