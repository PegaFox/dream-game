#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

#include "gui-lib/drag_box.hpp"

class Item
{
  public:
    // mass is in Kilograms, volume is in litres
  
    std::string name;

    virtual bool isContainer() = 0;

    virtual bool isHookable() = 0;

    virtual float getMass() = 0;

    virtual float getVolume() = 0;

    virtual void update() = 0;

    pfui::DragBox* getDrawBox()
    {
      return &drawBox;
    }

  protected:
    pfui::DragBox drawBox;

    static void setupDrawBox(Item* item);
};

#endif
