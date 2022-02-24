#pragma once
#include <SFML/Graphics.hpp>

using std::string;

class Menu_label : public sf::Drawable
{
private :
	sf::Text text;
public :
	Menu_label();
	Menu_label(double width, double height, sf::Font & font);
	void set_string(string line);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

