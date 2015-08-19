#include <string>
#include <vector>
#include <SFML\Graphics.hpp>

class Tilemap
{
public:
	
	void draw(sf::RenderWindow &window);
	std::vector<sf::Sprite>& create(const int* tiles, int tilesX, int tilesY, int tileSizeX, int tileSizeY, int amountOfTiles, std::string filePath);
	std::vector<sf::Sprite> collectables;
	void drawCollectables(sf::RenderWindow &window);
private:
	sf::Texture tileTexture;
	std::vector<sf::Sprite> levelTiles;
};