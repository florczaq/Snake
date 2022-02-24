#pragma once

#include<SFML/Graphics.hpp>

class Signature : public sf::Drawable
{
private:
	sf::Text text;
public :
	Signature();
	Signature(sf::Font& font, double width, double height);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

