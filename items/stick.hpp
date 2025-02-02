#ifndef ITEMS_STICK_HPP
#define ITEMS_STICK_HPP

#include "../item.hpp"

class Stick: public Item
{
  public:
    Stick()
    {
      name = "Stick";
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
};

#endif