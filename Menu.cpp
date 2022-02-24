#include "Menu.h"

const float Menu::get_difficulty(){
	return difficulty;
}

bool Menu::windowIsOpen(){
	return window->isOpen();
}


Menu::~Menu(){
	delete window;
}

void Menu::initWindow(){
	window = new sf::RenderWindow(windowWH, "Menu", sf::Style::None);
	window->setFramerateLimit(60);
}

Menu::Menu(double width, double height){
	initVariables(width, height);
	initWindow();
}

void Menu::render(){
	window->clear(sf::Color(81, 21, 81));
	window->draw(ml);
	if (!started)
		for (int i = 0; i < 2; i++)
			window->draw(buttons[i]);
	else
		for (int i = 2; i < 5; i++)
			window->draw(buttons[i]);

	window->draw(buttons[5]);
	window->display();
}

void Menu::initVariables(double width, double height){
	windowWH.width = width;
	windowWH.height = height;
	font.loadFromFile("Fonts/font2.ttf");
	ml = Menu_label(width, height, font);
	moveRectangle = MoveRectangle(width*0.87, height*0.08, sf::Color::Transparent, sf::Vector2f(width*0.45, (height*0.08)/2));
	buttons = {
		Button(font, width / 1.5, height / 7, "Start", sf::Color(0, 160, 10), sf::Vector2f(width / 2, height * 0.5)),	// 0 start
		Button(font, width / 1.5, height / 7, "Exit", sf::Color(160, 10, 0), sf::Vector2f(width / 2, height * 0.75)),	// 1 exit
		Button(font, width / 1.5, height / 7, "\nEasy", sf::Color(0,100, 0), sf::Vector2f(width / 2, height * 0.45)),	// 2 easy
		Button(font, width / 1.5, height / 7, "Medium", sf::Color(207, 155, 0), sf::Vector2f(width / 2, height * 0.65)),// 3 medium
		Button(font, width / 1.5, height / 7, "Hard", sf::Color(150, 0, 0), sf::Vector2f(width / 2, height * 0.85)),		// 4 hard
		Button(font, width * 0.1, width * 0.1, "X", sf::Color(255,0,100, 50), sf::Vector2f(width - (width * 0.1) / 1.5, width * (0.1) / 1.5)) // exit X
	};
}

void Menu::events(){
	while (window->pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			difficulty = -1;
			window->close();
			exit(1);
			break;

		case sf::Event::MouseMoved:
			mc.set_position(sf::Vector2f(sf::Mouse::getPosition(*window)));
			for (int i = 0; i < buttons.size(); i++)
				mc.get_bounds().intersects(buttons[i].get_bounds()) ? buttons[i].hover(true) : buttons[i].hover(false);
			break;

		case sf::Event::MouseButtonPressed:

			if (mc.pressed(buttons[2].get_bounds()) && started)
				difficulty = 2.0, window->close();				// easy
			if (mc.pressed(buttons[3].get_bounds()) && started) // medium
				difficulty = 1.5, window->close();
			if (mc.pressed(buttons[4].get_bounds()) && started) // hard
				difficulty = 1, window->close();
			if (mc.pressed(buttons[0].get_bounds()))			// start
				started = true;
			if (!started &&mc.pressed(buttons[1].get_bounds()) || mc.pressed(buttons[5].get_bounds())) // exit
				exit(2);
			break;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (mc.get_bounds().intersects(moveRectangle.get_bounds())) {
				moveRectangle.move(window, sf::Mouse::getPosition());
			}
		}
	}
}