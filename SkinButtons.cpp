#include "SkinButtons.h"

SkinButtons::SkinButtons()
{
}

SkinButtons::SkinButtons(sf::Vector2f size, sf::Vector2f position, sf::Font &font, float charSize, string line, sf::Texture &texture)
{
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);

	text.setFont(font);
	text.setCharacterSize(charSize);
	text.setString(line);
	text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);

	rectangle.setSize(size);
	rectangle.setPosition(position);
	rectangle.setOrigin(size.x/2, size.y/2);
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineColor(sf::Color::White);
	//rectangle.setOutlineThickness(1.2f);

	sprite.setPosition(position);
	text.setPosition(position.x, position.y+size.y*0.1);

}

bool SkinButtons::hover(sf::FloatRect mouseBounds){
	return mouseBounds.intersects(rectangle.getGlobalBounds());
}

void SkinButtons::hoverStyle(bool hovered)
{
	if (hovered) {
		rectangle.setOutlineThickness(4);
		rectangle.setScale(1.1, 1.1);
	}
	else {
		rectangle.setOutlineThickness(0);
		rectangle.setScale(1, 1);
	}
}

void SkinButtons::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
	target.draw(sprite);
	target.draw(text);
}
