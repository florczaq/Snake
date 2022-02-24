#include "Skins.h"

void Skins::set_blue_color(SnakeHead &head, SnakeBody &body)
{
	head.set_color(sf::Color(0, 150, 199));
	body.set_color(sf::Color(0, 119, 182));
}

void Skins::set_green_color(SnakeHead& head, SnakeBody& body)
{
	head.set_color(sf::Color(0, 255, 0));
	body.set_color(sf::Color(51, 204, 51));
}

void Skins::set_purple_color(SnakeHead& head, SnakeBody& body)
{
	head.set_color(sf::Color(72, 34, 124));
	body.set_color(sf::Color(70, 40, 170));
}

void Skins::set_yellow_color(SnakeHead& head, SnakeBody& body)
{
	head.set_color(sf::Color(255,240,2));
	body.set_color(sf::Color(245, 230, 2));
}

sf::Color Skins::pickRandColor()
{
	pickerID++;
	switch (pickerID) {
	case 1: return sf::Color(255, 0, 0); 
	case 2: return sf::Color(255, 135, 0); 
	case 3: return sf::Color(255, 211, 0); 
	case 4: return sf::Color(222, 255, 10);
	case 5: return sf::Color(161, 255, 10); 
	case 6: return sf::Color(10, 255, 153); 
	case 7: return sf::Color(10, 239, 255);
	case 8: return sf::Color(20, 125, 245); 
	case 9: return sf::Color(88, 10, 255); 
	case 10: pickerID = 0;
		return sf::Color(190, 10, 255); 
	}
}

void Skins::set_rainbow_color(SnakeHead& head, SnakeBody& body)
{
	if (skinID == 3) {
		body.set_color(head.getColor());
		head.set_color(pickRandColor());
	}
}

void Skins::setSkin(int id){
	skinID = id;
}

void Skins::updateSkin(SnakeHead& head, SnakeBody& body)
{
	switch (skinID) {
	case 0:
		set_blue_color(head, body);
		break;
	case 1:
		set_green_color(head, body);
		break;
	case 2:
	default:
		set_purple_color(head,body);
		break;
	case 3:
		set_rainbow_color(head,body);
		break;
	case 4:
		set_yellow_color(head, body);
		break;

	case 5:
		set_purple_color(head, body);
		break;
	}
}
