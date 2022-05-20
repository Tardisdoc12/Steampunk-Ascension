#include<SFML/Audio.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "card.h"
#include "allcards.h"
using namespace std;
using namespace sf;

#ifndef __Deck_h__
#define __Deck_h__
class Deck:public sf::Drawable, public sf::Transformable{
private:
  vector<Card> deck_base;
public:
  Deck();
  std::vector<Card> createDeck(string classType);
  void melangeDeck();
  void Pioche(int number);
  void VoirLeDeck();
  void EnvoiLaMain();
  void rempliLeDeck();
  ~Deck();
  //virtual void draw(sf::RenderTarget & target,sf::RenderStates state) const;
};
#endif
