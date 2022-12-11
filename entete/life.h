#include<SFML/Audio.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
using namespace sf;

#ifndef __life_h__
#define __life_h__
class life: public sf::Transformable, public sf::Drawable{
private:
  sf::RectangleShape green;
  sf::RectangleShape red;
  sf::Text counter;
  sf::Font font;
  int counterLife;
  int lifeMax;
  float longueur=130.f;
  float hauteur=10.f;
public:
  life();
  void initialise(int ptDevie); //define the number of life
  life(int ptDeVie);
  void PerteDeVie(int degat);//inflict damage
  void GainDeVie(int gain);//gain life
  void setMaxVie(int i);//set the maximum life
  void setPosition(sf::Vector2f Pos);//define the position
  virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;//drawing the life
};

#endif
