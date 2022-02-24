#include "Game_score.h"

Game_score::Game_score()
{
}

Game_score::Game_score(sf::Font& font, double width, double height)
{
	text.setFont(font);
	text.setCharacterSize(90);
	text.setString("SCORE: 0");
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	text.setPosition(width / 2, height / 3);
	text.setOutlineThickness(2);
	text.setOutlineColor(sf::Color::Black);
	text.setFillColor(sf::Color(255,255,255,10));
}

void Game_score::set_string(int score)
{
	text.setString("SCORE: " + to_string(score));
	if (score%10 == 0)
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

void Game_score::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(text);
}
