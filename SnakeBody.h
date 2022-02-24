#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using std::vector;

class SnakeBody : public sf::Drawable
{
private:
	vector <sf::RectangleShape> rectangles;
	sf::RectangleShape new_rect(sf::Vector2f position);
	sf::Vector2f old_pos;
	sf::Color bodyColor = sf::Color(70, 40, 170);
	float width = 0, height = 0;
public:
	SnakeBody();
	SnakeBody(float ww, float wh, sf::Vector2f pos);
	
	vector <sf::RectangleShape> get_shapes();

	bool body_colision(sf::FloatRect head);
	void afterMove(sf::Vector2f pos);
	void add_body();
	void set_color(sf::Color color);
	int getVectorSize();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

