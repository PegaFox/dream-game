#include "room.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

Room::Room(glm::uvec2 size): size(size), tiles(size.x * size.y)
{

}

tile_t& Room::at(glm::uvec2 pos)
{
  return tiles[pos.y * size.x + pos.x];
}

void Room::update()
{

}

void Room::draw(sf::RenderTarget& SCREEN, glm::vec2 origin, float tileSize, const std::map<tile_t, sf::Texture>& tileTextures)
{
  for (int y = 0; y < size.y; y++)
  {
    for (int x = 0; x < size.x; x++)
    {
      std::map<tile_t, sf::Texture>::const_iterator tex = tileTextures.find(at(glm::uvec2(x, y)));
      if (tex != tileTextures.cend())
      {
        sf::Sprite sprite(tex->second);
        sprite.setScale(tileSize / tex->second.getSize().x, tileSize / tex->second.getSize().y);
        sprite.setPosition(windowSize.x*0.5f + x*tileSize - tileSize*0.5f - origin.x*tileSize, windowSize.y*0.5f + y*tileSize - tileSize*0.5f - origin.y*tileSize);
        SCREEN.draw(sprite);
      } else
      {
        sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
        rect.setFillColor(sf::Color(at(glm::uvec2(x, y))));
        rect.setPosition(windowSize.x*0.5f + x*tileSize - tileSize*0.5f - origin.x*tileSize, windowSize.y*0.5f + y*tileSize - tileSize*0.5f - origin.y*tileSize);
        SCREEN.draw(rect);
      }
    }
  }

  for (Entity* entity: entities)
  {
    entity->draw(SCREEN, origin, tileSize);
  }
}
