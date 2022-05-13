#include<SFML/Audio.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "card.h"
using namespace std;
using namespace sf;

#ifndef __Deck_h__
#define __Deck_h__
class Deck{
private:
  vector<Card> deck;
  vector<Card> main;
  vector<Card> defausse;

public:
  Deck();
  void melangeDeck();
  void Pioche();
  void VoirLeDeck();
  void EnvoiLaMain();
  void rempliLeDeck();
  virtual void draw(sf::RenderTarget & target,sf::RenderStates state) const;
};
#endif
