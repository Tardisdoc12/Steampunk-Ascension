#include<SFML/Audio.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "life.h"
#include "Card.h"
#include "Deck.h"
using namespace std;
using namespace sf;

#ifndef __Player_h__
#define __Player_h__

class Player: public sf::Transformable, public sf::Drawable{
private:
  life joueur_life;
  std::string class_player="None";
  sf::Texture skin;
  sf::Sprite joueur;
  std::vector<Card> Plateformer;
  Deck deck_fight;
  std::vector<Card> Hand;
  std::vector<Card> GY;
  std::vector<Card> Defausse;
  bool isInFight=false;
public:
  Player();
  void initialiseLife(int Vie);
  void deplacement();
  void setClassType(string classType);
  void setPosition(sf::Vector2f Pos);
  virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
  void Onfight();
  void Notfight();
};
#endif
