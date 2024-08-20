#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <pegafox/utils.hpp>

#include "player.hpp"

int main() {
  pf::FPS fpsClock;
  srand(time(0));
  sf::RenderWindow SCREEN(sf::VideoMode(512, 512), "RPG game");
  SCREEN.setFramerateLimit(60);
  while (SCREEN.isOpen()) {
    sf::Event event;
    while (SCREEN.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          SCREEN.close();
          break;
      }
    }

    

    SCREEN.clear();
    
    SCREEN.display();
    SCREEN.setTitle(std::to_string(int(fpsClock.get_fps())));
  }
  return 0;
}