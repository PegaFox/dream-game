#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <filesystem>

#define USE_PEGAFOX_UTILS_IMPLEMENTATION
#include <pegafox/utils.hpp>

#include "world.hpp"

#include "player.hpp"

#include "gui_manager.hpp"

std::string rootDir;

glm::uvec2 windowSize(512U, 512U);
sf::RenderWindow SCREEN(sf::VideoMode(windowSize.x, windowSize.y), "RPG game", sf::Style::Close);

GUIManager gui;

int main() {
  const std::string_view searchDirs[] = {"./", "../"};

  for (const std::string_view& dir: searchDirs)
  {
    if (std::filesystem::is_directory(std::filesystem::path(std::string(dir) + "assets")))
    {
      std::cout << "using root dir \"" << dir << "\"\n";
      
      rootDir = dir;
      break;
    }
  }

  Text::font.loadFromFile(rootDir + "assets/fonts/PublicPixel.ttf");

  pf::FPS fpsClock;

  Player player;

  World world(player);

  gui.addElement(Text());
  gui[0]->pos = glm::vec2(-1.0f);
  gui[0]->size = glm::vec2(0.05f);
  ((Text*)gui[0])->text.setFillColor(sf::Color(100, 50, 0));
  ((Text*)gui[0])->text.setString("Inventory");

  gui.addElement(Rect());
  gui[1]->pos = glm::vec2(-0.35f, -0.95);
  gui[1]->size = glm::vec2(0.65f, 0.05);
  ((Rect*)gui[1])->shape.setFillColor(sf::Color(0, 50, 0));

  gui.addElement(Window({gui[1], gui[0]}));
  gui[0]->size = glm::vec2(0.5f);
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
    {
      gui[0]->size *= glm::vec2(0.99f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
    {
      gui[0]->size *= glm::vec2(1.01f);
    }
    
    player.update();
    SCREEN.clear();
    
    world.draw(SCREEN, player.pos);

    gui[0]->draw();

    SCREEN.display();
    SCREEN.setTitle(std::to_string(int(fpsClock.get_fps())));
  }
  return 0;
}