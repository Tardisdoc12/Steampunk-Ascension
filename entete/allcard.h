#ifndef ALLCARD_H
#define ALLCARD_H
#include <iostream>
#include <fstream>
#include<vector>
#include "entete/card.h"
class allcard
{
private:
    std::fstream myData;
    std::vector<std::string> Cards;
    std::vector<Card> allCards;
    Card Temporary;
public:
    allcard(std::string & file);
    bool load(std::string & file);
    void draw(sf::RenderWindow & window);
    void setPosition(sf::Vector2f position);
    void draganddrop(sf::RenderWindow & window);
    void agrandisouris(sf::RenderWindow & window);
    void always();
};

#endif // ALLCARD_H
