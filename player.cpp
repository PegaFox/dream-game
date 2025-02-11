#include "player.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "gui-lib/paragraph.hpp"
#include "gui-lib/drag_field.hpp"
#include "items/stick.hpp"

extern std::string rootDir;
extern sf::RenderWindow SCREEN;

Player::Player()
{
  sprite.loadFromFile(rootDir + "assets/entities/test_character.png");

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

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    pos.y -= 0.1f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
  {
    pos.y += 0.1f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    pos.x -= 0.1f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    pos.x += 0.1f;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
  {
    leftHand.push_back(new Stick());
  }
}
