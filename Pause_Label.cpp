#include "Pause_Label.h"

Pause_Label::Pause_Label(int charSize, sf::Vector2f position, string line, sf::Font &font)
{
	//font.loadFromFile("font4.ttf");
	
	text.setFont(font);
	text.setCharacterSize(charSize);
	text.setString(line);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height/2);
	text.setPosition(position);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2);
}

Pause_Label::Pause_Label()
{
}

void Pause_Label::set_string(string s)
{
	text.setString(s);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

void Pause_Label::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(text);
}
