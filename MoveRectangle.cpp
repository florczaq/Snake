#include "MoveRectangle.h"

MoveRectangle::MoveRectangle()
{
}

MoveRectangle::MoveRectangle(double width, double height, sf::Color color, sf::Vector2f position)
{
	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setOrigin(width/2, height/2);
	rectangle.setFillColor(color);
	rectangle.setPosition(position);
}

sf::FloatRect MoveRectangle::get_bounds()
{
	return rectangle.getGlobalBounds();
}

void MoveRectangle::move(sf::RenderWindow *window, sf::Vector2i mousePosition)
{
//	if (mousec.circle.getGlobalBounds().intersects(border.rectangle.getGlobalBounds()))
//		window.setPosition(sf::Vector2i(sf::Mouse::getPosition().x - w_w / 2, sf::Mouse::getPosition().y - w_h / 20));
	window->setPosition(sf::Vector2i(mousePosition.x- window->getSize().x/2, mousePosition.y - window->getSize().y*0.05));
}

void MoveRectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
}
