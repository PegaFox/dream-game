class Rect;

#ifndef RECT_HPP
#define RECT_HPP

#include "gui_element.hpp"

#include <glm/vec4.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Rect: public GUIElement
{
  public:
    sf::RectangleShape shape;

    Rect();

    virtual void draw(bool useGuiCoords = true);
  private:
    
};

#endif