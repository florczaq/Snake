#include "Button.h"

Button::Button(){}

Button::Button(sf::Font & font, double width, double height, string s_text, sf::Color color, sf::Vector2f position){
	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setOrigin(width/2, height/2);
	rectangle.setFillColor(color);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(2);
	this->col = color;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setPosition(rectangle.getPosition());
	text.setString(s_text);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height*1.7);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2);
}

Button::Button(sf::Font& font, double width, double height, string s_text, sf::Color color, sf::Vector2f position, float charSize,sf::Color textColor){
	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setOrigin(width / 2, height / 2);
	rectangle.setFillColor(color);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(2);
	
	this->col = color;
	text.setFont(font);
	text.setCharacterSize(charSize);
	text.setPosition(rectangle.getPosition());
	text.setFillColor(textColor);
	text.setString(s_text);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height /2);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(0);
}


sf::FloatRect Button::get_bounds(){
	return rectangle.getGlobalBounds();
}

void Button::hover(bool hovered)
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

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(rectangle);
	target.draw(text);
}