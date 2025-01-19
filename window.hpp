class Window;

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <cstdint>
#include <array>
#include <SFML/Graphics/RectangleShape.hpp>
#include "gui_element.hpp"
#include "rect.hpp"

class Window: public GUIElement
{
  public:
    Window(const std::initializer_list<GUIElement*>& children = {});

    virtual void draw(bool useGuiCoords = true);
  private:
    std::pair<std::array<GUIElement*, 32>, uint8_t> children;
    Rect body;
};

#endif