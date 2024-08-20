class Player {
  public:
    Player() {
      
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const {
      target.draw(sprite);
    }
  private:
    sf::Sprite sprite;
    sf::Texture tex;
};