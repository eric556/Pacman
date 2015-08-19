
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <math.h>
#include <iostream>
#include "player.h"
#include "tilemap.h"
 
class Game
{
public:
	Game(int width, int height, std::string title, int frameLimit);
	void update(sf::Time ft);

public:
	sf::RenderWindow m_Window;
	inline bool isPlaying(){ return playing; }

private:
	void getInput();
	void draw();
	void createBackground(std::string filePath, float width, float height);
	void createLevel(const int* tiles, int tilesX, int tilesY,int tileSizeX,int tileSizeY, int amountOfTiles, std::string filePath);

private:
	bool playing;
	std::vector<sf::Sprite> background;
	std::vector<sf::Sprite> level;
	std::vector<sf::Sprite> entitys;
	std::vector<sf::Sprite> gui;
	sf::Texture bg;
	sf::Texture tileTexture;
	//std::vector<sf::Texture> tiles;
	int x = 0;
	int y = 0;
	Tilemap level1Tiles;
	Player player;
	sf::Time frameTime;
	sf::Texture playerText;
	sf::RectangleShape rect;
};