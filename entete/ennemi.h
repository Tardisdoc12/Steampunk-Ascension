#include<SFML/Audio.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "life.h"
#include "card.h"
using namespace std;

#ifndef __ennemi_h__
#define __ennemi_h__
class Ennemy:public sf::Transformable, public sf::Drawable{
private:
  vector<Card> deck;//---->Class deck??
  sf::Sprite ennemi;
  sf::Texture im;
  int nombreDeMana;
  life ennemi_life;//lifepoint;
  //class type--->quel type d'ennemi
public:
  Ennemy(int ptDeVie);
  void setPosition(sf::Vector2f Pos);
  void setScale(sf::Vector2f Taille);
  virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};

#endif
