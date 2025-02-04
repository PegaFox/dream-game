#include "window.hpp"

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
  if (children.second == 32)
  {
    return nullptr;
  }

  children.first[children.second++].reset(child);
  return children.first[children.second-1].get();
}

bool Window::removeChild()
{
  if (children.second == 0)
  {
    return false;
  }

  children.first[--children.second].reset();
  return true;
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