#include "Game.h"

const bool Game::windowIsOpen() {
	return window->isOpen();
}

int Game::getResult()
{
	return result;
}

Game::~Game()
{
	delete window;
}

void Game::rendWindow(double width, double height) {
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Snake", sf::Style::Close);
	window->setFramerateLimit(80);
}

Game::Game(double width, double height, float difficulty) {
	if (difficulty == -1) exit(1);
	this->difficulty = difficulty;

	initVars(width, height);
	rendWindow(width, height);

}

void Game::render()
{
	window->clear(sf::Color(16, 01, 16));
	window->draw(gameScore);
	window->draw(signature);

	if (!paused && !end && !picking) {
		window->draw(pauseButton);
		window->draw(skinPickerButton);
	}
	window->draw(snakeBody);
	window->draw(snakeHead);
	window->draw(point);

	if (paused) window->draw(pauseMenu);
	if (end) window->draw(endMenu);
	if (picking) window->draw(skinPicker);

	window->display();
}
  
void Game::snakeMove(sf::Clock& frameTime)
{
	snakeHead.move();
	snakeBody.afterMove(snakeHead.get_pos());
	skins.set_rainbow_color(snakeHead, snakeBody);
	frameTime.restart();
	if (point.collision(snakeHead.get_shape().getGlobalBounds())) { // add func get bounds in SnakeHead
		point.pick_new_position(snakeBody.get_shapes(), snakeHead.get_shape().getSize().x);
		snakeBody.add_body();
		score++;
		gameScore.set_string(score);
	}
	if (snakeBody.body_colision(snakeHead.get_shape().getGlobalBounds())) {
		end = true;
		endMenu.set_score(score);
	}
}

void Game::update(sf::Clock& frameTime) {
	events(frameTime);
	if (frameTime.getElapsedTime().asMilliseconds() >= 70 * difficulty && !paused && !end && !picking)
		snakeMove(frameTime);
}

void Game::initVars(double width, double height) {
	font.loadFromFile("Fonts/font4.ttf");
	pixelFont.loadFromFile("Fonts/pixel.ttf");
	signFont.loadFromFile("Fonts/font_s.ttf");

	textures.push_back(loadTexture("Images/blue.png"));
	textures.push_back(loadTexture("Images/green.png"));
	textures.push_back(loadTexture("Images/purple.png"));
	textures.push_back(loadTexture("Images/rainbow.png"));
	textures.push_back(loadTexture("Images/yellow.png"));
	pointTexture.loadFromFile("Images/apple.png");

	snakeHead = SnakeHead(width, height);
	snakeBody = SnakeBody(width, height, snakeHead.get_pos());
	point = Point(width, height, snakeBody.get_shapes(), snakeHead.get_shape().getSize().x, pointTexture);
	pauseMenu = Pause(font, width, height, false);
	endMenu = Pause(font, width, height, true);
	gameScore = Game_score(pixelFont, width, height);
	signature = Signature(signFont, width, height);
	pauseButton = Button(pixelFont, width * 0.03, height * 0.055, "||", sf::Color::Transparent, sf::Vector2f(width * 0.95, height * 0.05), 31, sf::Color(255, 255, 255, 30));
	skinPickerButton = Button(pixelFont, width * 0.03, height * 0.055, "s", sf::Color::Transparent, sf::Vector2f(width * 0.9, height * 0.045), 41, sf::Color(255, 255, 255, 30));
	skinPicker = SkinPicker(width / 2, height * 0.8, sf::Color(61, 21, 61), sf::Vector2f(width / 2, height / 2), font, textures);
}

void Game::events(sf::Clock& frameTime)
{
	while (window->pollEvent(event)) {

		if (!window->hasFocus())
			paused = true;

		switch (event.type)
		{
		case  sf::Event::Closed:
			result = -1;
			window->close();
			exit(1);
			break;

		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::Escape && !end)
				paused = paused ? false : true;
			break;

		case sf::Event::MouseMoved:
			mouseCursor.set_position(sf::Vector2f(sf::Mouse::getPosition(*window)));
			if (paused) pauseMenu.hover(mouseCursor.get_bounds());
			else if (end) endMenu.hover(mouseCursor.get_bounds()); \
			else if (picking) skinPicker.hover(mouseCursor.get_bounds(), false);
			break;

		case sf::Event::MouseButtonPressed:

			if (event.mouseButton.button == sf::Mouse::Left) {

				if (!picking) {
					if ((pauseMenu.pressed(mouseCursor.get_bounds(), paused) == 2 && paused) || (endMenu.pressed(mouseCursor.get_bounds(), paused) == 2 && end)) {
						result = 1;
						window->close();
					}
				}
				else {
					int* temp = new int(skinPicker.hover(mouseCursor.get_bounds(), true));
					if (*temp != - 1) {
						skins.setSkin(*temp);
						skins.updateSkin(snakeHead, snakeBody);
						picking = false;
					}
					delete temp;
				}

				if (mouseCursor.pressed(skinPickerButton.get_bounds())) {
					picking = true;
				}

				if (mouseCursor.pressed(pauseButton.get_bounds())) {
					paused = true;
				}
			}

			break;

		case sf::Event::KeyPressed:

			if (!paused && !end && snakeHead.changeDirection(event.key.code))
				snakeMove(frameTime);
			break;
		}
	}
}

sf::Texture Game::loadTexture(string path)
{
	sf::Texture texture;
	texture.loadFromFile(path);
	return texture;
}
