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
  // Visuel de la carte--------------------------------------------------------------------------------------------------
  sf::Texture image;
  sf::Sprite imageSprite;
  sf::Texture skin;
  sf::Sprite Card_skin;
  sf::Font font;
  sf::Text name;
  sf::Text Mana;
  sf::Text Description;
  // Variables de la carte-------------------------------------------------------------------------------------------------
  bool agrandi=false;
  bool drag=false;
  float taille;
  int Type=0;
  vector<string> DescriptionOrEffects;
  vector<int> Effects;
public:
  // on créer la carte------------------------------------------------------------------------------------------------------
  Card();

  //On récupère des données de la carte--------------------------------------------------------------------------------------
  int cost();
  string getName();
  void readEffects();
  //on met en place la carte------------------------------------------------------------------------------------------------
  void setMana(std::string mana);
  void setDescription(std::string desc);
  void setImage(std::string path_to_image);
  void setName(std::string nom);
  void setType(std::string type);

  //transformation de la carte----------------------------------------------------------------------------------------------
  void setPosition(sf::Vector2f newPos);
  void setScale(sf::Vector2f dim);
  void move(sf::Vector2f distance);
  void setRotation(float angle);
  sf::FloatRect getGlobalBounds();
  void setOrigin(float newX,float newY);
  float getX();
  float getY();

  //Le gamplay---------------------------------------------------------------------------------------------------------------
  void agrandisouris(sf::RenderWindow & window);
  void dragAndDrop(sf::RenderWindow & window);
  void follow(sf::RenderWindow & window);
  vector<int> getEffect();

  // on dessine la carte----------------------------------------------------------------------------------------------------
  virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};


#endif
