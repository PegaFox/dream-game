/*
  Stack based approach
    - Each GUI element can have a set of pointers to children and a relative position
    - GUI elements relay movement and visibility data to their children
    - Central array of GUI elements

    pros
      - we don't need to handle too many dynamic pointers
      - it's easy to iterate over all elements
      - better for cache
    cons
      - we need a central manager class to hold the stack
*/

class GUIManager;

#ifndef GUI_MANAGER_HPP
#define GUI_MANAGER_HPP

#include <array>
#include <cstdint>
#include "window.hpp"
#include "text.hpp"
#include "button.hpp"

class GUIManager
{
  public:
    GUIElement* addElement(const Window& window);

    GUIElement* addElement(const Text& text);

    GUIElement* addElement(const Button& button);

    GUIElement* addElement(const Rect& rect);

    //bool removeElement(GUIElement* element);

    const GUIElement* operator[](uint8_t index) const;

    GUIElement* operator[](uint8_t index);
  private:
    GUIElement* at(uint8_t index);

    std::pair<std::array<Window, 32>, uint8_t> windows;
    std::pair<std::array<Text, 32>, uint8_t> text;
    std::pair<std::array<Button, 32>, uint8_t> buttons;
    std::pair<std::array<Rect, 32>, uint8_t> rects;
};

#endif