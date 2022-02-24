#pragma once
#include <SFML/Graphics.hpp>

using std::string;

class Pause_texts : public sf::Drawable
{
private:
	sf::Text pause_text;
	sf::Font font;
public:
	Pause_texts(sf::Vector2f position, string line, int size);
	Pause_texts();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

