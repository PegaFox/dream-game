class Text;

#ifndef TEXT_HPP
#define TEXT_HPP

#include "gui_element.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class Text: public GUIElement
{
  public:
    static sf::Font font;
    sf::Text text;

    Text();

    Text(std::string filename);

    virtual void draw(bool useGuiCoords = true);
  private:

};

#endif