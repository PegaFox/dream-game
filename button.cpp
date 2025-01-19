#include "button.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

extern sf::RenderWindow SCREEN;

Button::Button()
{
  type = ElementType::Button;
}

void Button::draw(bool useGuiCoords)
{

  body.setPosition(sf::Vector2f(40.0f, 40.0f));
  body.setSize(sf::Vector2f(400.0f, 400.0f));
  SCREEN.draw(body);
}