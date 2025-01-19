#include "text.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

extern sf::RenderWindow SCREEN;
extern glm::uvec2 windowSize;
extern std::string rootDir;

Text::Text()
{
  type = ElementType::Text;

  text.setString("Hello, World!");
}

void Text::draw(bool useGuiCoords)
{
  text.setCharacterSize(windowSize.y);
  text.setFont(font);
  text.setPosition(sf::Vector2f((pos.x+1.0f)*windowSize.x*0.5f, (pos.y+1.0f)*windowSize.y*0.5f));
  text.setScale(sf::Vector2f(size.x, size.y));
  SCREEN.draw(text);
}

sf::Font Text::font;