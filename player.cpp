#include "player.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "gui_classes/text.hpp"

extern std::string rootDir;

Player::Player()
{
  sprite.loadFromFile(rootDir + "assets/entities/test_character.png");

  inventoryMenu.size = glm::vec2(0.75f, 0.75f);

  Text* inventoryDescription = new Text();
  inventoryDescription->pos = glm::vec2(-0.98f, -0.98f);
  inventoryDescription->size = glm::vec2(0.04f, 0.04f);
  inventoryDescription->text.setFillColor(sf::Color(100, 50, 0));

  inventoryMenu.addChild(inventoryDescription);

  pos = glm::vec2(4.0f);
}

void Player::update()
{
  ((Text*)inventoryMenu[0])->text.setString("Inventory");

  inventoryMenu.draw();

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
}
