#include<SFML/Audio.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "entete/life.h"
#include "entete/card.h"
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
  Ennemy(int ptDeVie); //create the ennemy
  void setPosition(sf::Vector2f Pos);//define the position
  void setScale(sf::Vector2f Taille);//define the scale
  virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;//drawing the ennemy
  Sprite returnSprite() const;//return the sprte of the ennemy
};

#endif
