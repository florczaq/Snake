#include "Menu_label.h"

Menu_label::Menu_label()
{ 
}

Menu_label::Menu_label(double width, double height, sf::Font & font){
	text.setFont(font);
	text.setCharacterSize(110);
	text.setString("SNAKE");
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	text.setPosition(width / 2, height / 10);
	text.setOutlineThickness(3);
	text.setOutlineColor(sf::Color::Black);
}

void Menu_label::set_string(string s) {
	text.setString(s);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

void Menu_label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(text);
}
