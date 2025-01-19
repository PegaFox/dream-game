#include "window.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

extern sf::RenderWindow SCREEN;
extern glm::uvec2 windowSize;

Window::Window(const std::initializer_list<GUIElement*>& children)
{
  type = ElementType::Window;

  body.shape.setFillColor(sf::Color(150, 50, 0));

  for (GUIElement* child: children)
  {
    this->children.first[this->children.second++] = std::unique_ptr<GUIElement>(child);
  }
}

GUIElement* Window::addChild(GUIElement* child)
{
  children.first[children.second++].reset(child);
}

bool Window::removeChild()
{
  children.first[--children.second].reset();
}

GUIElement* Window::operator[](uint8_t index)
{
  if (index < children.second)
  {
    return children.first[index].get();
  }
  return nullptr;
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