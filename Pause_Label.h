#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using std::string, std::cout, std::endl;

class Pause_Label : public sf::Drawable
{
private:
	sf::Text text;
	//sf::Font font;
public:
	Pause_Label(int charSize, sf::Vector2f position, string line, sf::Font &font);
	Pause_Label();
	void set_string(string s);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};