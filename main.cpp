#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <filesystem>

#define USE_PEGAFOX_UTILS_IMPLEMENTATION
#include <pegafox/utils.hpp>

#include "world.hpp"

#include "player.hpp"

#include "gui_classes/text.hpp"

std::string rootDir;

glm::uvec2 windowSize(512U, 512U);
sf::RenderWindow SCREEN(sf::VideoMode(windowSize.x, windowSize.y), "RPG game", sf::Style::Close);

int main()
{
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

  Rect* testRect = new Rect;
  testRect->pos = glm::vec2(-0.35f, -0.95);
  testRect->size = glm::vec2(0.65f, 0.05);
  testRect->shape.setFillColor(sf::Color(0, 50, 0));

  Text* testText = new Text;
  testText->pos = glm::vec2(-1.0f);
  testText->size = glm::vec2(0.05f);
  testText->text.setFillColor(sf::Color(100, 50, 0));
  testText->text.setString("Inventory");

  Window testWindow({testRect, testText});
  testWindow.size = glm::vec2(0.5f);

  SCREEN.setFramerateLimit(60);
  while (SCREEN.isOpen())
  {
    sf::Event event;
    while (SCREEN.pollEvent(event))
    {
      switch (event.type)
      {
        case sf::Event::Closed:
          SCREEN.close();
          break;
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
    {
      
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
    {

    }
    
    SCREEN.clear();

    world.draw(SCREEN, player.pos);

    player.update();

    SCREEN.display();
    SCREEN.setTitle(std::to_string(int(fpsClock.get_fps())));
  }
  return 0;
}