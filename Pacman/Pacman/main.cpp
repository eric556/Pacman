#include "game.h"

int main()
{
	Game game(640, 640, "Pacman", 60);
	sf::Clock frameClock;
  while (game.isPlaying())
  {
	  game.update(frameClock.restart());
  }

  return 0;
}