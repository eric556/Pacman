#include "player.h"

void Player::create(sf::RenderWindow &window, sf::Texture &playerText)
{
	AnimatedSprite placeHolder(sf::seconds(0.2), true, false);
	sprite = placeHolder;

	movingUpAnimation.setSpriteSheet(playerText);
	movingUpAnimation.addFrame(sf::IntRect(0, 96, 32, 32));
	movingUpAnimation.addFrame(sf::IntRect(32, 96, 32, 32));

	movingDownAnimation.setSpriteSheet(playerText);
	movingDownAnimation.addFrame(sf::IntRect(0, 32, 32, 32));
	movingDownAnimation.addFrame(sf::IntRect(32, 32, 32, 32));

	movingRightAnimation.setSpriteSheet(playerText);
	movingRightAnimation.addFrame(sf::IntRect(0, 0, 32, 32));
	movingRightAnimation.addFrame(sf::IntRect(32, 0, 32, 32));

	movingLeftAnimation.setSpriteSheet(playerText);
	movingLeftAnimation.addFrame(sf::IntRect(0, 64, 32, 32));
	movingLeftAnimation.addFrame(sf::IntRect(32, 64, 32, 32));

	currentAnimation = &movingRightAnimation;
	sprite.play(*currentAnimation);
	m_Velocity = 100.f;
	m_VelocityVector.x = m_Velocity;
	m_VelocityVector.y = 0;
	amountOfCollectablesCollected = 0;
	
	sprite.setOrigin(sf::Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2));
	sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
}

void Player::update(sf::Time ft, std::vector<sf::Sprite> sprites, std::vector<sf::Sprite> &collectables)
{
	checkForCollisions(sprites, collectables);
	sprite.update(ft);
	getInput(ft);
}

void Player::getInput(sf::Time ft)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_VelocityVector.x = -m_Velocity;
		m_VelocityVector.y = 0;
		currentAnimation = &movingLeftAnimation;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		m_VelocityVector.x = m_Velocity;
		m_VelocityVector.y = 0;
		currentAnimation = &movingRightAnimation;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		m_VelocityVector.x = 0;
		m_VelocityVector.y = m_Velocity;
		currentAnimation = &movingDownAnimation;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		m_VelocityVector.x = 0;
		m_VelocityVector.y = -m_Velocity;
		currentAnimation = &movingUpAnimation;
	}
	sprite.play(*currentAnimation);
	sprite.move(m_VelocityVector * ft.asSeconds());
}

void Player::checkForCollisions(std::vector<sf::Sprite> sprites, std::vector<sf::Sprite> &collectables)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		
		boundingBox.width = sprite.getGlobalBounds().width - 16;
		boundingBox.height = sprite.getGlobalBounds().height - 18;
		boundingBox.left = sprite.getPosition().x - (boundingBox.width/2);
		boundingBox.top = sprite.getPosition().y - (boundingBox.height/2);
		if (boundingBox.intersects(sprites[i].getGlobalBounds()))
		{
			if (m_VelocityVector.x == m_Velocity)
			{
				sprite.setPosition(sf::Vector2f(sprite.getPosition().x - 2, sprite.getPosition().y));
				m_VelocityVector.x = 0;
				m_VelocityVector.y = 0;
				//std::cout << "collision!\n";
			}
			if (m_VelocityVector.x == -m_Velocity)
			{
				sprite.setPosition(sf::Vector2f(sprite.getPosition().x + 2.4, sprite.getPosition().y));
				m_VelocityVector.x = 0;
				m_VelocityVector.y = 0;
			}
			if (m_VelocityVector.y == m_Velocity)
			{
				sprite.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y - 2));
				m_VelocityVector.x = 0;
				m_VelocityVector.y = 0;
			}
			if (m_VelocityVector.y == -m_Velocity)
			{
				sprite.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + 2));
				m_VelocityVector.x = 0;
				m_VelocityVector.y = 0;
			}
		}
	}
	for (int i = 0; i < collectables.size(); i++)
	{
		if (boundingBox.intersects(collectables[i].getGlobalBounds()))
		{
			if (collectables[i].getColor() != sf::Color(0, 0, 0, 0))
			{
				collectables[i].setColor(sf::Color(0, 0, 0, 0));
				amountOfCollectablesCollected++;
			}
		} 
	}
	if (amountOfCollectablesCollected == collectables.size())
	{
		std::cout << "You win!\n";
		amountOfCollectablesCollected = 0;
	}
}