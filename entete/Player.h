#include<SFML/Audio.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "life.h"
using namespace std;
using namespace sf;

#ifndef __Player_h__
#define __Player_h__
class Player: public sf::Transformable, public sf::Drawable{
private:
  life joueur_life;
  sf::Texture skin;
  sf::Sprite joueur;
  bool isInFight=false;
public:
  Player();
  void initialiseLife(int Vie);
  void deplacement();
  void setPosition(sf::Vector2f Pos);
  virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
  void Onfight();
  void Notfight();
};
#endif
