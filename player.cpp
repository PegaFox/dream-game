#include "player.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "text.hpp"

extern std::string rootDir;

Player::Player() {
  sprite.loadFromFile(rootDir + "assets/entities/test_character.png");

  Text* inventoryDescription = new Text();

  inventoryMenu.addChild(inventoryDescription);

  pos = glm::vec2(4.0f);
}

void Player::update()
{
  

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    pos.y -= 0.1f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    pos.y += 0.1f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    pos.x -= 0.1f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    pos.x += 0.1f;
  }
}
