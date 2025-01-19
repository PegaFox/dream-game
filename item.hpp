#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item {
  public:
    // mass is in Kilograms, volume is in litres
    struct EquipmentFlags {
      bool head: 1;
      bool chest: 1;
      bool leftHand: 1;
      bool rightHand: 1;
      bool legs: 1;
      bool leftFoot: 1;
      bool rightFoot: 1;
    } equipmentFlags;

    std::string name;

    virtual float getMass() = 0;

    virtual float getVolume() = 0;
};

#endif