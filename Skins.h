#pragma once

#include<vector>
#include<iostream>

#include "SnakeBody.h"
#include "SnakeHead.h"

#include <SFML/Graphics.hpp>

using std::vector;

class Skins 
{
private :
	int skinID = 0;
	int pickerID = 0;
	void set_blue_color(SnakeHead &head, SnakeBody &body);
	void set_green_color(SnakeHead &head, SnakeBody &body);
	void set_purple_color(SnakeHead &head, SnakeBody &body);
	void set_yellow_color(SnakeHead &head, SnakeBody &body);
	
	sf::Color pickRandColor();
public :
	void set_rainbow_color(SnakeHead& head, SnakeBody& body);
	void setSkin(int id);
	void updateSkin(SnakeHead& head, SnakeBody& body);
};