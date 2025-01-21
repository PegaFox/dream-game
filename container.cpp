#include "container.hpp"

#include <cstdint>

#include "item.hpp"

void Container::addChild(Item* child, uint8_t index = -1)
{
  if (contents.second == 32)
  {
    return;
  }

  contents.first[contents.second++].reset(child);
}

bool Container::removeChild(uint8_t index = -1)
{
  if (contents.second == 0)
  {
    return false;
  }

  contents.first[--contents.second].reset();
  return true;
}

Item* Container::operator[](uint8_t index)
{
  if (index < contents.second)
  {
    return contents.first[index].get();
  }
  return nullptr;
}
