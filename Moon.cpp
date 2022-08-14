#include "Moon.hpp"

Moon::Moon(float posX, float posY, float velX, float velY) {
	pos.x = posX;
	pos.y = posY;

	vel.x = velX;
	vel.y = velY;

	s.setPosition(pos);
	s.setFillColor(sf::Color::Green);
	s.setRadius(10);
}

void Moon::render(sf::RenderWindow& window) {
	s.setPosition(pos);
	window.draw(s);
}

void Moon::updatePhys(Planet& planet) {
	float distX = planet.getPos().x - pos.x;
	float distY = planet.getPos().y - pos.y;

	float dist = sqrt(distX * distX + distY * distY);

	float inverseDist = 1 / dist;

	float normX = inverseDist * distX;
	float normY = inverseDist * distY;

	float gravityDrop  = inverseDist * inverseDist;     //F ~ 1/d^2 proportionate

	float accelX = normX * planet.getStrength() * gravityDrop;
	float accelY = normY * planet.getStrength() * gravityDrop;

	vel.x += accelX;
	vel.y += accelY;

	//bounce off the walls
	// if (pos.x < 0 || pos.x > 1920 - 30)
	// 	vel.x *= -1;

	// if (pos.y < 0 || pos.y > 1080 - 50)
	// 	vel.y *= -1;

	if (pos.x < 0) {
		pos.x = 1920;
	} else if (pos.x > 1920) {
		pos.x = 0;
	}

	if (pos.y < 0)
		pos.y = 1080;
	else if (pos.y > 1080)
		pos.y = 0; 

	pos.x += vel.x;
	pos.y += vel.y;

}
