#include "game.h"

Game::Game(int width, int height, std::string title, int frameLimit) : m_Window(sf::VideoMode(width, height), title)
{
	m_Window.setFramerateLimit(frameLimit);
	playing = true;
	m_Window.clear(sf::Color(100,200,55,255));
	m_Window.display();
	int test[] =
	{
		4, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 6,
		17, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 17,
		17, 30, 4, 9, 9, 9, 9, 9, 9, 6, 4, 9, 9, 9, 9, 9, 9, 6, 30, 17,
		17, 30, 17, 30, 30, 30, 30, 30, 30, 27, 27, 30, 30, 30, 30, 30, 30, 17, 30, 17,
		17, 30, 17, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 17, 30, 17,
		17, 30, 17, 30, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 30, 17, 30, 17,
		17, 30, 17, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 17, 30, 17,
		17, 30, 27, 30, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 30, 27, 30, 17,
		17, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 17,
		17, 30, 1, 3, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 1, 3, 30, 17,
		17, 30, 21, 23, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 21, 23, 30, 17,
		17, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 17,
		17, 30, 7, 30, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 30, 7, 30, 17,
		17, 30, 17, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 17, 30, 17,
		17, 30, 17, 30, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 30, 17, 30, 17,
		17, 30, 17, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 17, 30, 17,
		17, 30, 17, 30, 30, 30, 30, 30, 30, 7, 7, 30, 30, 30, 30, 30, 30, 17, 30, 17,
		17, 30, 24, 9, 9, 9, 9, 9, 9, 26, 24, 9, 9, 9, 9, 9, 9, 26, 30, 17,
		17, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 17,
		24, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 26



	};
	int testLevelFinal[400];
	for (int i = 0; i < 400; i++)
	{
		testLevelFinal[i] = test[i] - 1;
	}
	this->createBackground("pacmanBackground.png", 100, 100);
	level = level1Tiles.create(testLevelFinal, 20, 20, 32, 32, 31, "pacmanTilemap1.png");
	if (!playerText.loadFromFile("playerSpriteSheet.png"))
	{
		std::cout << "oops\n";
	}
	player.create(m_Window, playerText);
}

void Game::update(sf::Time ft)
{
	this->getInput();
	player.update(ft, level, level1Tiles.collectables);
	this->draw();
}


void Game::draw()
{
	m_Window.clear();
	for (int i = 0; i < background.size(); i++)
	{
		m_Window.draw(background[i]);
	}
	
	level1Tiles.draw(m_Window);
	level1Tiles.drawCollectables(m_Window);
	m_Window.draw(player.sprite);
	m_Window.display();
}

void Game::createBackground(std::string filePath, float width, float height)
{
	int debug = 0;
	int tilesX = ceil((m_Window.getSize().x / width));
	int tilesY = ceil((m_Window.getSize().y / height));
	if (!bg.loadFromFile(filePath))
	{
		std::cout << "couldnt load background!" << "\n";
	}

	for (int i = 0; i < tilesY; i++)
	{
		for (int j = 0; j < tilesX; j++)
		{
			debug += 1;
			sf::Sprite bgTile;
			bgTile.setTexture(bg);
			bgTile.setPosition(j * width, i * height);
			this->background.push_back(bgTile);
		}
	}
	std::cout << debug << "\n";
}

void Game::getInput()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			playing = false;
		}
	}
}
