#include "tilemap.h"


std::vector<sf::Sprite>& Tilemap::create(const int* tiles, int tilesX, int tilesY, int tileSizeX, int tileSizeY, int amountOfTiles, std::string filePath)
{
	tileTexture.loadFromFile(filePath);
	int j = 0;
	for (int y = 0; y < tilesY; y++)
	{
		for (int x = 0; x < tilesX; x++)
		{
			if (tiles[j] == (amountOfTiles - 1)){
				//std::cout << x << ", " << y << "\n";
			}
			else{
				if (tiles[j] != 29){
					sf::Sprite tile;
					tile.setTexture(tileTexture);
					tile.setTextureRect(sf::IntRect(tileSizeX * tiles[j], 0, tileSizeX, tileSizeY));
					//tile.setOrigin()
					tile.setPosition(x * tileSizeX, y * tileSizeY);
					levelTiles.push_back(tile);
				}
				else
				{
					sf::Sprite collectable;
					collectable.setTexture(tileTexture);
					collectable.setTextureRect(sf::IntRect(tileSizeX * tiles[j], 0, tileSizeX, tileSizeY));
					collectable.setPosition(x * tileSizeX, y * tileSizeY);
					collectables.push_back(collectable);
				}
			}
			j = j + 1;
		}
	}
	return levelTiles;
}

void Tilemap::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < levelTiles.size(); i++)
	{
		window.draw(levelTiles[i]);
	}
}

void Tilemap::drawCollectables(sf::RenderWindow &window)
{
	for (int i = 0; i < collectables.size(); i++)
	{
		window.draw(collectables[i]);
	}
}