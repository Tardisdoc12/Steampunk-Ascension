#include<SFML/Audio.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "entete/life.h"
#include "entete/card.h"
#include "entete/Deck.h"
#include "entete/Floor.h"
#include "entete/ennemi.h"
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
  std::vector<Card> deck_Plateformer;
  Deck deck_fight;
  std::vector<Card> Hand;
  std::vector<Card> GY;
  std::vector<Card> Defausse;
  sf::RectangleShape glob;
  bool isInFight=false;
public:
  Player();
  void initialiseLife(int Vie);
  void deplacement(Floor & floor);
  void move(sf::Vector2f distance);
  sf::Vector2f getPosition();
  void setClassType(string classType/*,carddata & allcards*/);
  void setPosition(sf::Vector2f Pos);
  sf::FloatRect getGlobalBounds();
  virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
  void Onfight();
  void Notfight();
  void EnterBattle(Ennemy & ennemy);
};
#endif
