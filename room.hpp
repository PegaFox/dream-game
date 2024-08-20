#include <vector>
#include <cstdint>

typedef uint32_t tile_t;

class Room
{
  public:
    Room(glm::uvec2 size): size(size), tiles(size.x * size.y)
    {

    }

    tile_t& at(glm::uvec2 pos)
    {
      return tiles[pos.y * size.x + pos.x];
    }

    void update()
    {

    }

    void draw()
    {

    }
  private:
    glm::uvec2 size;
    std::vector<tile_t> tiles;
};