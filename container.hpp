class Container;

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <cstdint>
#include <array>
#include <memory>

#include "item.hpp"

class Container: public Item
{
  public:
    void addChild(Item* child, uint8_t index = -1);

    bool removeChild(uint8_t index = -1);

    Item* operator[](uint8_t index);

  private:
    std::pair<std::array<std::unique_ptr<Item>, 32>, uint8_t> contents;
};

#endif