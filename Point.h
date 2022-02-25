#pragma once

#include <SFML/Graphics.hpp>

using std::vector;

class Point : public sf::Drawable
{
private:
	sf::RectangleShape rectangle;

	float width = 0, height = 0;
	sf::Sprite sprite;
	bool free_pos(int x, int y, vector<sf::RectangleShape> rects, float snake_width);
	bool randomColor = false;
	short lasPickedNumber = -1;
	int pickNewNumber(int seed);
public:

	Point();
	Point(float wwidth, float wheight, vector <sf::RectangleShape> rectangles, float snake_width, sf::Texture& texture);

	sf::Color getColor();
	void changeColor();
	void switchRandomColor(bool randomColor);
	void pick_new_position(vector <sf::RectangleShape> rectangles, float snake_width);
	bool collision(sf::FloatRect rect);
	const bool isRandom();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};