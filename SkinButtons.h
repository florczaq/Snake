#pragma once

#include <SFML/Graphics.hpp>

using std::string;

class SkinButtons : public sf::Drawable
{
private:
	sf::Sprite sprite;
	sf::RectangleShape rectangle;
	sf::Text text;
public:
	SkinButtons();
	SkinButtons(sf::Vector2f size, sf::Vector2f position, sf::Font &font, float charSize, string textString, sf::Texture& texture);
	bool hover(sf::FloatRect mouseBounds);
	void hoverStyle(bool hovered);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

