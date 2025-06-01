#ifndef ITEMS_STICK_HPP
#define ITEMS_STICK_HPP

#include "../item.hpp"
#include "../gui-lib/paragraph.hpp"

class Stick: public Item
{
  public:
    Stick()
    {
      name = "Stick";

      setupDrawBox(this);
      
      description.pos = glm::vec2(-0.9f, -0.9f);
      description.size = glm::vec2(0.3f, 1.8f);
      description.text.setString("Stick");
      drawBox.addChild(&description);
    }

    virtual bool isContainer()
    {
      return false;
    }

    virtual bool isHookable()
    {
      return false;
    }

    virtual float getMass()
    {
      return 1.0f;
    }

    virtual float getVolume()
    {
      return 0.75f;
    }

    virtual void update()
    {
      
    }

  private:
    pfui::Paragraph description;
};

#endif
