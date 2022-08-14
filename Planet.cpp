#include "Planet.hpp"

Planet::Planet(float posX, float posY, float velX, float velY, float strength) {
	pos.x = posX;
	pos.y = posY;
	this->strength = strength;
	vel.x = velX;
	vel.y = velY;

	s.setPosition(pos);
	s.setFillColor(sf::Color::Red);
	s.setRadius(25);
}

void Planet::render(sf::RenderWindow& window) {
	window.draw(s);
}

sf::Vector2f Planet::getPos() {
	s.setPosition(pos);
	return pos;
}

float Planet::getStrength() {
	return strength;
}

void Planet::updatePhys() {

	//teleport to the opposite wall
	if (pos.x < 0) {
		pos.x = 1920;
	} else if (pos.x > 1920) {
		pos.x = 0;
	}

	if (pos.y < 0)
		pos.y = 1080;
	else if (pos.y > 1080)
		pos.y = 0; 

	//move the planet
	pos.x += vel.x;
	pos.y += vel.y;
}

void Planet::speedUp() {
	vel.x++;
}

void Planet::slowDown() {
	vel.x--;
}




