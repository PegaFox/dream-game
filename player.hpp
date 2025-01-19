class Player;

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"

#include "room.hpp"

#include "item.hpp"

#include "window.hpp"

class Player: public Entity
{
  public:
    Room* currentRoom;

    Player();

    void update();

  private:
    std::vector<Item*> hand;

    Window inventoryMenu;
};

#endif