#include "item.hpp"

void Item::setupDrawBox(Item* item)
{
  sf::Color oldBackgroundColor = pfui::GUIElement::defaultBackgroundColor;
  float mass = item->getMass();

  pfui::GUIElement::defaultBackgroundColor = sf::Color(mass, 255 - mass, 0);
  item->drawBox = pfui::DragBox();

  item->drawBox.size.y = item->getVolume()*0.25f;
}
