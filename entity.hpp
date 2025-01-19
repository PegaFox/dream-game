class Entity;

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <glm/vec2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

extern glm::uvec2 windowSize;

class Entity
{
  public:
    glm::vec2 pos = glm::vec2(0, 0);

    virtual void draw(sf::RenderTarget& SCREEN, glm::vec2 origin, float tileSize) const {
      sf::Sprite blit(sprite);
      blit.scale(sf::Vector2f(tileSize / sprite.getSize().x, tileSize / sprite.getSize().y));
      blit.setPosition(sf::Vector2f(windowSize.x*0.5f + pos.x*tileSize - tileSize*0.5f - origin.x*tileSize, windowSize.y*0.5f + pos.y*tileSize - tileSize*0.5f - origin.y*tileSize));
      SCREEN.draw(blit);
    }
  
  protected:
    sf::Texture sprite;
};

#endif