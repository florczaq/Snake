#include "Signature.h"

Signature::Signature()
{ 
}

Signature::Signature(sf::Font & font, double width, double height) {
	text.setFont(font);
	text.setCharacterSize(20);
	text.setString("Made by: Mikolaj Florczak");
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	text.setPosition(width / 2, height *0.98);
	text.setOutlineThickness(1);
	text.setOutlineColor(sf::Color::Black);
	text.setFillColor(sf::Color(56, 41, 56,100));
}

void Signature::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(text);
}
