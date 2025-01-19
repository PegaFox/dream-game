#include "rect.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

extern sf::RenderWindow SCREEN;
extern glm::uvec2 windowSize;

Rect::Rect()
{
  type = ElementType::Rect;
}

void Rect::draw(bool useGuiCoords)
{
  shape.setPosition(sf::Vector2f((pos.x-size.x+1.0f)*windowSize.x*0.5f, (pos.y-size.y+1.0f)*windowSize.y*0.5f));
  shape.setSize(sf::Vector2f(windowSize.x*size.x, windowSize.y*size.y));
  SCREEN.draw(shape);
}