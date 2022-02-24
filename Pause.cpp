#include "Pause.h"

Pause::Pause()
{
}

Pause::Pause(sf::Font& font, double windowWidth, double windowHeight, bool end)
{
	background = Pause_button(sf::Vector2f(windowWidth / 2, windowHeight * 0.8), sf::Color(61, 21, 61), sf::Vector2f(windowHeight / 2, windowHeight / 2));
	restart = Pause_button(sf::Vector2f(background.get_size().x * 0.6, background.get_size().y * 0.15), sf::Color(80, 60, 80), sf::Vector2f(windowWidth / 2, windowHeight * 0.65));
	leave = Pause_button(sf::Vector2f(background.get_size().x * 0.6, background.get_size().y * 0.15), sf::Color(80, 60, 80), sf::Vector2f(windowWidth / 2, windowHeight * 0.8));
	l_rest = Pause_Label(70,  restart.get_position(), "Restart\n", font);
	l_exit = Pause_Label(70, leave.get_position(), "Exit\n", font);

	if (!end) {
		resume = Pause_button(sf::Vector2f(background.get_size().x * 0.6, background.get_size().y * 0.15), sf::Color(80, 60, 80), sf::Vector2f(windowWidth / 2, windowHeight * 0.5));
		l_resu = Pause_Label(70, resume.get_position(), "Resume\n", font);
		main_label = Pause_Label(100, sf::Vector2f(background.get_position().x, background.get_position().y - background.get_size().y * 0.4), "Paused", font);
	}
	else {
		main_label = Pause_Label(100, sf::Vector2f(background.get_position().x, background.get_position().y - background.get_size().y * 0.4), "Game Over", font);
		score_label = Pause_Label(90, sf::Vector2f(background.get_position().x, background.get_position().y - background.get_size().y * 0.15), "SCORE: 0", font);
	}
}

int Pause::pressed(sf::FloatRect mouse_bounds, bool &paused){
	if (mouse_bounds.intersects(resume.get_bounds())) 
		paused = false;
	else if (mouse_bounds.intersects(restart.get_bounds())) 
		return 2;
	else if (mouse_bounds.intersects(leave.get_bounds())) 
		exit(1);
	return 0;
}

void Pause::set_score(int score)
{
	score_label.set_string("SCORE: " + to_string(score));
}

void Pause::hover(sf::FloatRect mc)
{
	restart.get_bounds().intersects(mc) ? restart.hover(true) : restart.hover(false);
	resume.get_bounds().intersects(mc) ? resume.hover(true) : resume.hover(false);
	leave.get_bounds().intersects(mc) ? leave.hover(true) : leave.hover(false);

}

void Pause::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background);
	target.draw(restart);
	target.draw(resume);
	target.draw(leave);

	target.draw(main_label);
	target.draw(score_label);
	target.draw(l_resu);
	target.draw(l_rest);
	target.draw(l_exit);
}
