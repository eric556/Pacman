#include <SFML\Graphics.hpp>
#include "AnimatedSprite.h"
#include <iostream>
#include <vector>
#include <string>

class Player 
{
public:
	void update(sf::Time ft, std::vector<sf::Sprite> sprites, std::vector<sf::Sprite> &collectables);
	void create(sf::RenderWindow &window, sf::Texture &playerText);
public:
	AnimatedSprite sprite;
	sf::Rect<float> boundingBox;
private:
	void getInput(sf::Time ft);
	void checkForCollisions(std::vector<sf::Sprite> sprites, std::vector<sf::Sprite> &collectables);
private:
	Animation movingUpAnimation;
	Animation movingDownAnimation;
	Animation movingLeftAnimation;
	Animation movingRightAnimation;
	Animation* currentAnimation;
	float m_Velocity;
	sf::Vector2f m_VelocityVector;
	int amountOfCollectablesCollected;

};