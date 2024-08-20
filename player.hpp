class Player {
  public:
    Room* currentRoom;

    Player() {
      
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const {
      target.draw(sprite);
    }
  private:
    sf::Sprite sprite;
    sf::Texture tex;
};