#include<SFML/Audio.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "entete/card.h"
//#include "allcards.h"
using namespace std;
using namespace sf;

#ifndef __Deck_h__
#define __Deck_h__
class Deck/*:public sf::Drawable, public sf::Transformable*/{
private:
  vector<Card> deck_base;
public:
  Deck();
  void createDeck(string classType/*,carddata & allcards*/); //create the deck of the player or the ennemy.
  void melangeDeck(); //shuffle the deck
  void Pioche(int number);//draw at the beginning of the turn or for effect
  void VoirLeDeck(); // let see the deck for the player
  void EnvoiLaMain(); // draw the hand at the beginning of the fight
  void rempliLeDeck(); // when there is no card in the deck send the discard cards in the deck
  ~Deck();
  //virtual void draw(sf::RenderTarget & target,sf::RenderStates state) const;
};
#endif
