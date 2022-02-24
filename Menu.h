#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Menu_label.h"
#include "Button.h"
#include "Mouse_cursor.h"
#include "MoveRectangle.h"

using std::vector, std::cout, std::endl;

class Menu 
{
private:
	sf::VideoMode windowWH;
	sf::Event event;
	sf::RenderWindow *window;
	sf::Font font;

	MoveRectangle moveRectangle;
	Mouse_cursor mc;
	Menu_label ml;
	vector <Button> buttons;

	void initVariables(double width, double height);
	void initWindow();
	bool started = false;
	float difficulty = 2.0;
public:
	Menu(double width, double height);
	virtual ~Menu();
	bool windowIsOpen();
	void events();
	void render();
	const float get_difficulty();
};

