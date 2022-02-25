#include "SkinPicker.h"

SkinPicker::SkinPicker(){}

SkinPicker::SkinPicker(double width, double height, sf::Color color, sf::Vector2f position, sf::Font &font, vector<sf::Texture>&texture)
{
	this->width = width;
	this->height = height;

	background.setFillColor(color);
	background.setPosition(position);
	background.setSize(sf::Vector2f(width, height));
	background.setOrigin(width / 2, height / 2);
	
	text.setFont(font);
	text.setCharacterSize(110);
	text.setString("Skins");
	text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(3);
	text.setPosition(position.x, height*0.20);

	blueSkin = SkinButtons(sf::Vector2f(width *0.45, height * 0.2), sf::Vector2f(position.x - width * 0.25, position.y - height * 0.12), font, 70, "Blue", texture.at(0));
	greenSkin = SkinButtons(sf::Vector2f(width * 0.45, height * 0.2), sf::Vector2f(position.x + width * 0.25, position.y - height * 0.12), font, 70, "Green",texture.at(1));
	purpleSkin = SkinButtons(sf::Vector2f(width * 0.45, height * 0.2), sf::Vector2f(position.x - width * 0.25, position.y + height * 0.13), font, 70, "Purple",texture.at(2));
	rainbowSkin = SkinButtons(sf::Vector2f(width * 0.45, height * 0.2), sf::Vector2f(position.x + width * 0.25, position.y + height * 0.13), font, 70, "Rainbow",texture.at(3));
	yellowSkin = SkinButtons(sf::Vector2f(width * 0.45, height * 0.2), sf::Vector2f(position.x - width * 0.25, position.y + height * 0.38), font, 70, "Yellow", texture.at(4));
	specialSkin = SkinButtons(sf::Vector2f(width * 0.45, height * 0.2), sf::Vector2f(position.x + width * 0.25, position.y + height * 0.38), font, 70, "Point's", texture.at(5));
}

int SkinPicker::hover(sf::FloatRect mouseBounds, bool pressed)
{
	if (blueSkin.hover(mouseBounds)) {
		if (!pressed) blueSkin.hoverStyle(true);
		else return 0;
	}
	else blueSkin.hoverStyle(false);


	if (greenSkin.hover(mouseBounds)) {
		if (!pressed) greenSkin.hoverStyle(true);
		else return 1;
	}
	else greenSkin.hoverStyle(false);


	if (purpleSkin.hover(mouseBounds)) {
		if (!pressed) purpleSkin.hoverStyle(true);
		else return 2;
	}
	else purpleSkin.hoverStyle(false);


	if (rainbowSkin.hover(mouseBounds)) {
		if (!pressed) rainbowSkin.hoverStyle(true);
		else return 3;
	}
	else rainbowSkin.hoverStyle(false);
	

	if (yellowSkin.hover(mouseBounds)) {
		if (!pressed) yellowSkin.hoverStyle(true);
		else return 4;
	}
	else yellowSkin.hoverStyle(false);

	if (specialSkin.hover(mouseBounds)) {
		if (!pressed) specialSkin.hoverStyle(true);
		else return 5;
	}
	else specialSkin.hoverStyle(false);

	return -1;
}




void SkinPicker::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background);
	target.draw(text);
	target.draw(blueSkin);
	target.draw(greenSkin);
	target.draw(purpleSkin);
	target.draw(rainbowSkin);
	target.draw(yellowSkin);
	target.draw(specialSkin);
}
