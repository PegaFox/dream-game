#include "gui_manager.hpp"

GUIElement* GUIManager::addElement(const Window& window)
{
  windows.first[windows.second++] = window;
  return &windows.first[windows.second-1];
}

GUIElement* GUIManager::addElement(const Text& text)
{
  this->text.first[this->text.second++] = text;
  return &this->text.first[this->text.second-1];
}

GUIElement* GUIManager::addElement(const Button& button)
{
  buttons.first[buttons.second++] = button;
  return &buttons.first[buttons.second-1];
}

GUIElement* GUIManager::addElement(const Rect& rect)
{
  rects.first[rects.second++] = rect;
  return &rects.first[rects.second-1];
}

/*bool GUIManager::removeElement(GUIElement* element)
{
  if (element >= windows.first.begin() && element < windows.first.end())
  {
    return &windows.first[index];
  }
  index -= windows.second;

  if (index < text.second)
  {
    return &text.first[index];
  }
  index -= text.second;

  if (index < buttons.second)
  {
    return &buttons.first[index];
  }
  index -= buttons.second;

  if (index < rects.second)
  {
    return &rects.first[index];
  }
  index -= rects.second;

  return nullptr;
}*/

const GUIElement* GUIManager::operator[](uint8_t index) const
{
  if (index < windows.second)
  {
    return &windows.first[index];
  }
  index -= windows.second;

  if (index < text.second)
  {
    return &text.first[index];
  }
  index -= text.second;

  if (index < buttons.second)
  {
    return &buttons.first[index];
  }
  index -= buttons.second;

  if (index < rects.second)
  {
    return &rects.first[index];
  }
  index -= rects.second;

  return nullptr;
}

GUIElement* GUIManager::operator[](uint8_t index)
{
  if (index < windows.second)
  {
    return &windows.first[index];
  }
  index -= windows.second;

  if (index < text.second)
  {
    return &text.first[index];
  }
  index -= text.second;

  if (index < buttons.second)
  {
    return &buttons.first[index];
  }
  index -= buttons.second;

  if (index < rects.second)
  {
    return &rects.first[index];
  }
  index -= rects.second;

  return nullptr;
}