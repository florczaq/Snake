#pragma once
//
#include <iostream>
#include <SFML/Graphics.hpp>

#include "SnakeHead.h"
#include "SnakeBody.h"
#include "Point.h"
#include "Pause.h"
#include "Game_score.h"
#include "Signature.h"
#include "Mouse_cursor.h"
#include "Button.h"
#include "Skins.h"
#include "SkinPicker.h"

using std::string;

class Game
{
private:
	sf::Event event;
	sf::RenderWindow* window;
	sf::Font font, pixelFont, signFont;
	vector<sf::Texture> textures;
	sf::Texture pointTexture;

	SnakeHead snakeHead;
	SnakeBody snakeBody;
	Point point;
	Pause pauseMenu, endMenu;
	Game_score gameScore;
	Signature signature;
	Mouse_cursor mouseCursor;
	Skins skins;
	Button pauseButton, skinPickerButton;
	SkinPicker skinPicker;

	bool paused = false, end = false, picking = false;
	float difficulty = -1;
	int score = 0, result = 1;
	void snakeMove(sf::Clock& frameTime);
	void initVars(double width, double height);
	void rendWindow(double width, double height);
	void events(sf::Clock& frameTime);
	sf::Texture loadTexture(string path);
public:
	Game(double width, double height, float difficulty);
	~Game();
	void update(sf::Clock& frameTime);
	const bool windowIsOpen();
	void render();
	int getResult();
};

