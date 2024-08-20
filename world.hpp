#include "room.hpp"
#include <filesystem>

class World
{
  public:
    World()
    {
      load();
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
      // load tiles
      for (const std::filesystem::__cxx11::directory_entry& entry : std::filesystem::directory_iterator("./assets/tiles"))
      {
        sf::Image tileImage;
        if (tileImage.loadFromFile(entry.path()))
        {
          tile_t tileIndex = std::stoul(entry.path().filename(), nullptr, 16);
          tiles[tileIndex].loadFromImage(tileImage);
        }
      }

      // load rooms
      for (const std::filesystem::__cxx11::directory_entry& entry : std::filesystem::directory_iterator("./assets/rooms"))
      {
        sf::Image roomImage;
        if (roomImage.loadFromFile(entry.path()))
        {
          world.push_back(Room(glm::uvec2(16, 16)));
          for (int y = 0; y < 16; y++)
          {
            for (int x = 0; x < 16; x++)
            {
              world.back().at(glm::uvec2(x, y)) = roomImage.getPixel(x, y).toInteger();
            }
          }
        }
      }
    }

    // size of a tile relative to the window
    float tileSize = 1.0f/16.0f;

    std::vector<Room> world;

    std::map<tile_t, sf::Texture> tiles;
};