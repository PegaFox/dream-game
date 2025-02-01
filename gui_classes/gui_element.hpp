class GUIElement;

#ifndef GUI_ELEMENT
#define GUI_ELEMENT

#include <glm/vec2.hpp>

class GUIElement
{
  public:
    enum class ElementType
    {
      None,// this is for invalid states and should not be used regularly in-game
      Window,
      Text,
      Button,
      Rect
    };

    // normalized, -1.0 to 1.0 range coordinate
    glm::vec2 pos = glm::vec2(0.0f);

    // normalized 0.0 to 1.0 coordinate representing size relative to render space
    glm::vec2 size = glm::vec2(1.0f);

    ElementType getType()
    {
      return type;
    }

    virtual void draw(bool useGuiCoords = true) = 0;
  protected:
    ElementType type;
};

#endif