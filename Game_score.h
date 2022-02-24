#pragma once

#include <SFML/Graphics.hpp>

using std::string, std::to_string;

class Game_score : public sf::Drawable
{
private :
	sf::Text text;
public :
	Game_score();
	Game_score(sf::Font& font, double width, double height);
	void set_string(int score);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

