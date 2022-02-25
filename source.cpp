//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Menu.h"
#include "Game.h"

using std::string;

const double WINDOW_HEIGHT = 840, WINDOW_WIDTH = WINDOW_HEIGHT;

float openMenu() {
	Menu menu(WINDOW_WIDTH / 2, WINDOW_HEIGHT * 0.8);
	while (menu.windowIsOpen()) {
		menu.events();
		menu.render();
	}
	return menu.get_difficulty();
}

int playGame(float difficulty) {
	
	Game game(WINDOW_WIDTH, WINDOW_HEIGHT, difficulty);
	sf::Clock frameTime;
	frameTime.restart();

	while (game.windowIsOpen()) {
		game.update(frameTime);
		game.render();
	}
	return game.getResult();
}

int main() {
	srand(time(NULL));
	while (playGame(openMenu()) == 1);
}
