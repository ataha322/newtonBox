#include <SFML/Graphics.hpp>

class Planet {
	private:
		sf::Vector2f pos;
		sf::Vector2f vel;
		float strength;
        sf::CircleShape s;

	public:
		//constructor
		Planet(float posX, float posY, float velX, float velY, float strength);

		//render our window
		void render(sf::RenderWindow& window);
		
		//return pos
		sf::Vector2f getPos();

		//return strength
		float getStrength();

		//make planet move and bounce
		void updatePhys();
		
		//increase speed by 1 in x-dir
		void speedUp();

		//decrease speed by 1 in x-dir
		void slowDown();
};
