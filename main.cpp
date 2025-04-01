#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <filesystem>

#define USE_PEGAFOX_UTILS_IMPLEMENTATION
#include <pegafox/utils.hpp>

#include "world.hpp"

#include "player.hpp"

#include "gui-lib/paragraph.hpp"

std::string rootDir;

glm::uvec2 windowSize(512U, 512U);
sf::RenderWindow SCREEN(sf::VideoMode(sf::Vector2u(windowSize.x, windowSize.y)), "RPG game", sf::Style::Close);

glm::uvec2 mPos(0U);
glm::ivec2 mDelta(0);

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

  if (!pfui::Paragraph::font.openFromFile(rootDir + "assets/fonts/PublicPixel.ttf"))
  {
    std::cout << "failed to find UI font\n";
  }

  pf::FPS fpsClock;

  Player player;

  World world(player);

  pfui::VertexArray* testRect = new pfui::VertexArray;
  testRect->shape.setPrimitiveType(sf::PrimitiveType::TriangleFan);
  testRect->shape.append(sf::Vertex(sf::Vector2f(-0.5f, -0.5f), sf::Color(0, 50, 0)));
  testRect->shape.append(sf::Vertex(sf::Vector2f(-0.5f, 0.5f), sf::Color(0, 50, 0)));
  testRect->shape.append(sf::Vertex(sf::Vector2f(0.5f, 0.5f), sf::Color(0, 50, 0)));
  testRect->shape.append(sf::Vertex(sf::Vector2f(0.5f, -0.5f), sf::Color(0, 50, 0)));
  testRect->pos = glm::vec2(-0.35f, -0.95);
  testRect->size = glm::vec2(0.65f, 0.05);

  pfui::Paragraph* testText = new pfui::Paragraph;
  testText->pos = glm::vec2(-1.0f);
  testText->size = glm::vec2(0.05f);
  testText->text.setFillColor(sf::Color(100, 50, 0));
  testText->text.setString("Inventory");

  pfui::Window testWindow({testRect, testText});
  testWindow.size = glm::vec2(0.5f);

  SCREEN.setFramerateLimit(60);
  while (SCREEN.isOpen())
  {
    mDelta = mPos;
    
    while (std::optional<sf::Event> event = SCREEN.pollEvent())
    {
      pfui::GUIElement::getEvent(event);
      
      if (event->is<sf::Event::Closed>())
      {
        SCREEN.close();
      } else if (const sf::Event::MouseMoved* move = event->getIf<sf::Event::MouseMoved>())
      {
        mPos = glm::uvec2(move->position.x, move->position.y);
      }
    }
    mDelta = glm::ivec2(mPos) - mDelta;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Hyphen))
    {
      
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Equal))
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
