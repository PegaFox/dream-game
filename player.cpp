#include "player.hpp"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "gui-lib/paragraph.hpp"
#include "gui-lib/drag_field.hpp"
#include "gui-lib/button.hpp"
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

  pfui::Button* leftHandButton = new pfui::Button();
  leftHandButton->pos = glm::vec2(-0.575f, -0.935f);
  leftHandButton->size = glm::vec2(0.85f, 0.075f);

  pfui::Button* rightHandButton = new pfui::Button();
  rightHandButton->pos = glm::vec2(-0.575f, -0.855f);
  rightHandButton->size = glm::vec2(0.85f, 0.075f);

  inventoryMenu.addChild(leftHandButton);
  inventoryMenu.addChild(rightHandButton);
  inventoryMenu.addChild(inventoryLables);

  leftHandMenu.setOpen(false);
  leftHandMenu.maximizeButton = false;
  leftHandMenu.minimizeButton = false;
  leftHandMenu.size = glm::vec2(1.0f, 1.0f);

  pfui::DragField* leftHandDragField = new pfui::DragField();
  leftHandMenu.addChild(leftHandDragField);

  rightHandMenu.setOpen(false);
  rightHandMenu.maximizeButton = false;
  rightHandMenu.minimizeButton = false;
  rightHandMenu.size = glm::vec2(1.0f, 1.0f);

  pfui::DragField* rightHandDragField = new pfui::DragField();
  rightHandMenu.addChild(rightHandDragField);

  pos = glm::vec2(4.0f);
}

void Player::update()
{
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

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
  {
    inventoryMenu.setOpen(true);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
  {
    leftHand.push_back(new Stick());

    pfui::DragBox* itemBox = new pfui::DragBox();
    itemBox->size.y = 0.5f;
    ((pfui::DragField*)leftHandMenu[0])->addChild(itemBox);
  }

  if (((pfui::Button*)inventoryMenu[0])->isPressed())
  {
    leftHandMenu.setOpen(true);
  }

  if (((pfui::Button*)inventoryMenu[1])->isPressed())
  {
    rightHandMenu.setOpen(true);
  }

  inventoryMenu.draw(SCREEN);
  leftHandMenu.draw(SCREEN);
  rightHandMenu.draw(SCREEN);
}
