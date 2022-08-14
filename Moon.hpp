#include "Planet.hpp"
#include "math.h"

class Moon {
	private:
		sf::Vector2f pos;
		sf::Vector2f vel;
        sf::CircleShape s;

	public:
		//constructor
		Moon(float posX, float posY, float velX, float velY);

		//render our window
		void render(sf::RenderWindow& window);

		//motion computations
		void updatePhys(Planet& planet);
		
};
