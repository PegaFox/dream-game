class World;

#ifndef WORLD_HPP
#define WORLD_HPP

#include "player.hpp"

class World
{
  public:
    // size of a tile in pixels
    float tileSize = 32;

    World(Player& player);

    void update();

    // origin is the worldspace location to be at the center of the screen
    void draw(sf::RenderTarget& SCREEN, glm::vec2 origin);

  private:
    void load();

    std::vector<Room> rooms;

    std::vector<Entity> entities;

    std::map<tile_t, sf::Texture> tileTextures;
};

#endif