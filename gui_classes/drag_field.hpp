class DragField;

#ifndef DRAG_FIELD_HPP
#define DRAG_FIELD_HPP

#include <array>
#include <memory>
#include <cstdint>
#include "gui_element.hpp"
#include "window.hpp"

class DragField: public GUIElement
{
  public:
    DragField(const std::initializer_list<Window*>& children = {});

    Window* addChild(Window* child, uint8_t index = -1);

    bool removeChild(uint8_t index = -1);

    Window* operator[](uint8_t index);

    virtual void draw(bool useGuiCoords = true);
  private:
    std::pair<std::array<std::unique_ptr<Window>, 32>, uint8_t> children;
    Rect body;
};

#endif