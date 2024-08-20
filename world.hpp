#include "room.hpp"
#include <filesystem>

class World
{
  public:
    World()
    {

    }

    void update()
    {

    }

    void draw()
    {

    }

  private:
    void load()
    {
      for (const auto& entry : std::filesystem::directory_iterator("assets/rooms"))
      {
        std::cout << entry.path() << std::endl;
      }
    }

    // size of a tile relative to the window
    float tileSize = 1.0f/16.0f;

    std::vector<Room> world;
};