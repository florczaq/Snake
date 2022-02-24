#include "Mouse_cursor.h"

Mouse_cursor::Mouse_cursor()
{
	circle.setRadius(1);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOrigin(circle.getLocalBounds().width / 2, circle.getLocalBounds().height / 2);
}

void Mouse_cursor::set_position(sf::Vector2f position)
{
	circle.setPosition(position);
}

bool Mouse_cursor::pressed(sf::FloatRect button_rect)
{
	return circle.getGlobalBounds().intersects(button_rect) ? true : false;
}

sf::FloatRect Mouse_cursor::get_bounds()
{
	return circle.getGlobalBounds();
}

void Mouse_cursor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(circle);
}
