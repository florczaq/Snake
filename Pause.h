#pragma once

#include <SFML/Graphics.hpp>
#include "Pause_Label.h"
#include "Pause_button.h"

using std::to_string;

class Pause : public sf::Drawable
{
private:
	Pause_button background, restart, resume, leave;
	Pause_Label main_label, l_resu, l_rest, l_exit, score_label;
public:
	Pause();
	Pause(sf::Font &font, double windowWidth, double windowHeight, bool end);
	int pressed(sf::FloatRect mouse_bounds, bool &paused);
	void set_score(int score);
	void hover(sf::FloatRect mc);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

