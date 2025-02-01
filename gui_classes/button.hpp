class Button;

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "gui_element.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

class Button: public GUIElement
{
  public:
    Button();

    virtual void draw(bool useGuiCoords = true);
  private:
    sf::RectangleShape body;
};

#endif