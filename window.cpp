#include "window.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

extern sf::RenderWindow SCREEN;
extern glm::uvec2 windowSize;

Window::Window(const std::initializer_list<GUIElement*>& children)
{
  type = ElementType::Window;

  body.shape.setFillColor(sf::Color(150, 50, 0));

  std::copy(children.begin(), children.end(), this->children.first.begin());
  this->children.second = children.size();
}

void Window::draw(bool useGuiCoords)
{
  body.pos = pos;
  body.size = size;
  body.draw();

  for (uint8_t c = 0; c < children.second; c++)
  {
    children.first[c]->pos *= size;
    children.first[c]->pos += pos;
    children.first[c]->size *= size;
    children.first[c]->draw();
    children.first[c]->size /= size;
    children.first[c]->pos -= pos;
    children.first[c]->pos /= size;
  }
}