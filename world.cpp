#include "world.hpp"

#include <filesystem>

World::World(Player& player)
{
  load();

  rooms[0].entities.push_back((Entity*)&player);
}

void World::update()
{

}

// origin is the worldspace location to be at the center of the screen
void World::draw(sf::RenderTarget& SCREEN, glm::vec2 origin)
{
  rooms[0].draw(SCREEN, origin, tileSize, tileTextures);
}


void World::load()
{
  // load tiles
  for (const std::string& searchDir: {"./assets/tiles", "../assets/tiles"})
  {
    if (!std::filesystem::exists(searchDir))
    {
      continue;
    }

    for (const std::filesystem::directory_entry& entry: std::filesystem::directory_iterator(searchDir))
    {
      sf::Image tileImage;
      if (tileImage.loadFromFile(entry.path()))
      {
        tile_t tileIndex = std::stoul(entry.path().filename(), nullptr, 16);
        tileTextures[tileIndex].loadFromImage(tileImage);
      }
    }
  }

  // load rooms
  for (const std::string& searchDir: {"./assets/rooms", "../assets/rooms"})
  {
    if (!std::filesystem::exists(searchDir))
    {
      continue;
    }

    for (const std::filesystem::__cxx11::directory_entry& entry: std::filesystem::directory_iterator(searchDir))
    {
      sf::Image roomImage;
      if (roomImage.loadFromFile(entry.path()))
      {
        rooms.push_back(Room(glm::uvec2(16, 16)));
        for (int y = 0; y < 16; y++)
        {
          for (int x = 0; x < 16; x++)
          {
            rooms.back().at(glm::uvec2(x, y)) = roomImage.getPixel(x, y).toInteger();
          }
        }
      }
    }
  }
}
