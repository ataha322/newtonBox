#include "Moon.hpp"
#include <iostream>
#include <string>

int main() {
	const std::string strControls = "Press  W  to  speed  up\nPress  S  to  slowdown\nPress  R  to  reset";
	const int FPS = 60;
	const int XRES = 1920; //frame size
	const int YRES = 1080;

	sf::Font font;
	if (!font.loadFromFile("fonts/ARCADECLASSIC.TTF")) {
		std::cerr << "couldn't load the font\n";
		return 42;
	}
	sf::Text text;
	text.setFont(font);
	text.setString(strControls);
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::White);




	sf::RenderWindow window(sf::VideoMode(XRES,YRES), "newtonBox");
	window.setFramerateLimit(FPS);

	Planet planet (960, 540, 0, 0, 5000);
	
	Moon moon(800, 640, 3, 3);


	while (window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				planet.speedUp();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				planet.slowDown();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				planet = Planet(960,540,0,0,5000);
				moon = Moon(800,640,3,3);
			}
		}


		window.clear();

		window.draw(text);
		planet.updatePhys();
		moon.updatePhys(planet);
		planet.render(window);
		moon.render(window);
		
		window.display();
	}

	return 0;
}
