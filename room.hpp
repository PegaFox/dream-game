class Room;

#ifndef ROOM_HPP
#define ROOM_HPP

/*#include <vector>
#include <cstdint>*/
#include <map>
#include "entity.hpp"

typedef uint32_t tile_t;

class Room
{
  public:
    std::vector<Entity*> entities;

    Room(glm::uvec2 size);

    tile_t& at(glm::uvec2 pos);

    void update();

    void draw(sf::RenderTarget& SCREEN, glm::vec2 origin, float tileSize, const std::map<tile_t, sf::Texture>& tileTextures);
  private:
    glm::uvec2 size;
    std::vector<tile_t> tiles;
};

#endif