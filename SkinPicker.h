#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "SkinButtons.h"

using std::vector;

class SkinPicker : public sf::Drawable
{
private:
	double width = 0, height = 0;
	sf::RectangleShape background;
	sf::Text text;
	SkinButtons blueSkin, greenSkin, purpleSkin, rainbowSkin, yellowSkin, specialSkin;
	sf::Texture blueTexture, greenTexture, purpleTexture, rainbowTexture;
public:
	SkinPicker();
	SkinPicker(double width, double height, sf::Color color, sf::Vector2f position,	sf::Font &font, vector<sf::Texture> &texture);
	int hover(sf::FloatRect mouseBounds, bool pressed);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

