#include "player.hpp"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "gui-lib/paragraph.hpp"
#include "items/stick.hpp"

extern std::string rootDir;
extern sf::RenderWindow SCREEN;

Player::Player()
{
  if (!sprite.loadFromFile(rootDir + "assets/entities/test_character.png"))
  {
    std::cout << "failed to load player sprite\n";
  }

  inventoryMenu.maximizeButton = false;
  inventoryMenu.minimizeButton = false;
  inventoryMenu.size = glm::vec2(1.5f, 1.5f);

  pfui::Paragraph* inventoryLables = new pfui::Paragraph();
  inventoryLables->pos = glm::vec2(-0.98f, -0.98f);
  inventoryLables->size = glm::vec2(0.08f, 0.08f);
  inventoryLables->text.setFillColor(sf::Color(100, 50, 0));
  inventoryLables->text.setString("Left Hand\nRight Hand");

  inventoryMenu.addChild(inventoryLables);

  pos = glm::vec2(4.0f);
}

void Player::update()
{
  inventoryMenu.draw(SCREEN);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
  {
    pos.y -= 0.1f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
  {
    pos.y += 0.1f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
  {
    pos.x -= 0.1f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
  {
    pos.x += 0.1f;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
  {
    leftHand.push_back(new Stick());
  }
}
