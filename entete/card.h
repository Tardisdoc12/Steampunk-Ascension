#include<SFML/Audio.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

#ifndef __card_h__
#define __card_h__

class Card: public sf::Drawable, public sf::Transformable{
private:
  sf::Texture image;
  sf::Sprite imageSprite;
  sf::Texture skin;
  sf::Sprite Card_skin;
  sf::Font font;
  sf::Text name;
  sf::Text Mana;
  sf::Text Description;
  sf::RenderStates state;
  bool agrandi=false;
  bool drag=false;
  float taille;
  int press=0;
  int block=0;
public:
  Card();
  //Card(std::string nom,std::string descr,std::string path_to_image);
  void setMana(std::string mana);
  int cost();
  void setDescription(std::string desc);
  void setImage(std::string path_to_image);
  void setName(std::string nom);
  void setPosition(sf::Vector2f newPos);
  void setScale(sf::Vector2f dim);
  void move(sf::Vector2f distance);
  void setRotation(float angle);
  sf::FloatRect getGlobalBounds();
  void setOrigin(float newX,float newY);
  float getX();
  float getY();
  void agrandisouris(sf::RenderWindow & window);
  void dragAndDrop(sf::RenderWindow & window);
  void follow(sf::RenderWindow & window);
  string getName();
  virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};


#endif
