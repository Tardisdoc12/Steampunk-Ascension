#ifndef CARD_H
#define CARD_H
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<entete/arrow.h>

class Card : public sf::Transformable, public sf::Drawable
{
private:
    sf::VertexArray card;
    sf::VertexArray Image_card;
    sf::FloatRect Bounds;
    sf::Font font;
    sf::Text Mana;
    sf::Text Description;
    sf::Text Name;
    sf::Texture card_back;
    sf::Texture card_image;
    sf::RectangleShape test;
    arrow point; //to help the player to target an ennemy with a card
    bool drag;
    bool agrandi;
    bool resize;
public: //the class card to play the game in fight or plaformer mode
    //--------Definition :
    Card();
    bool load();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::FloatRect getGlobalBounds();
    //____________set the data of the card :
    void setMana(std::string mana);
    void setDescription(std::string desc);
    void setImage(std::string path_to_image);
    void setName(std::string nom);
    void setType(std::string type);

    //-------------Gameplay :
    void DeplacePosition(sf::Vector2f dir);
    void agrandisouris(sf::RenderWindow & window);
    void dragAndDrop(sf::RenderWindow & window);
    void follow();
    std::vector<int> getEffect();


};

#endif // CARD_H
