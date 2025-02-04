class Window;

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <cstdint>
#include <array>
#include <memory>
#include "gui_element.hpp"
#include "rect.hpp"

class Window: public GUIElement
{
  public:
    Window(const std::initializer_list<GUIElement*>& children = {});

    GUIElement* addChild(GUIElement* child);

    bool removeChild();

    GUIElement* operator[](uint8_t index);

    virtual void draw(bool useGuiCoords = true);
  private:
    std::pair<std::array<std::unique_ptr<GUIElement>, 32>, uint8_t> children;
    Rect body;
};

#endif