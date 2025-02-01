#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
  public:
    // mass is in Kilograms, volume is in litres

    std::string name;

    virtual bool isContainer() = 0;

    virtual float getMass() = 0;

    virtual float getVolume() = 0;
};

#endif